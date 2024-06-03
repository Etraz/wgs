//
// Created by przem on 07.04.2024.
//
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <thread>
#include <vector>
#include <iostream>
#include "server/ConnectionManager.hpp"


//
//  std::vector<LocalConnectionManager> tables;
//    std::vector<int> fds;
//    sockaddr_in serverAddr;
//    int serverSocket;
//

ConnectionManager::ConnectionManager() {
    this->tables = std::vector<LocalConnectionManager>();
    this->fds = std::vector<int>();
    this->serverAddr = sockaddr_in();
    this->stoppage = false;
}

bool ConnectionManager::startup(int port) {
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        std::cerr << "Error creating socket\n";
        return false;
    }

    this->serverAddr.sin_family = AF_INET;
    this->serverAddr.sin_port = htons(port);
    this->serverAddr.sin_addr.s_addr = INADDR_ANY;
    if (bind(serverSocket, (sockaddr *) &serverAddr, sizeof(serverAddr)) == -1) {
        std::cerr << "Error binding socket\n";
        ::close(serverSocket);
        return false;
    }

    if (listen(serverSocket, SOMAXCONN) == -1) {
        std::cerr << "Error listening on socket\n";
        ::close(serverSocket);
        return false;
    }

    std::cout << "server properly started!\n";
    return true;
}

void ConnectionManager::close() {
    for (auto i: fds) {
        ::close(i);
    }
    ::close(serverSocket);
}


void ConnectionManager::addTable() {
    tables.emplace_back();
}

void ConnectionManager::loopAdd() {
    while (!stoppage) {
        sockaddr_in clientAddr{};
        socklen_t clientAddrSize = sizeof(clientAddr);
        int clientSocket = accept(serverSocket, (sockaddr *) &clientAddr, &clientAddrSize);
        if (clientSocket == -1) {
            std::cerr << "Error accepting connection\n";
            continue;
        }
        addUser(clientSocket);
    }
}

void ConnectionManager::addUser(int fd) {
    fds.emplace_back(fd);
}

void ConnectionManager::addUserTo(int index, int tbl) {
    tables.at(tbl).addUser(fds.at(index));
}

LocalConnectionManager &ConnectionManager::getTable(int index) {
    return tables.at(index);
}

void ConnectionManager::addUserToTemporary(int tbl) {
    int clientSocket = -1;
    while (clientSocket == -1) {
        sockaddr_in clientAddr{};
        socklen_t clientAddrSize = sizeof(clientAddr);
        clientSocket = accept(serverSocket, (sockaddr *) &clientAddr, &clientAddrSize);
        if (clientSocket == -1) {
            std::cerr << "Error accepting connection\n";
        } else {
            std::cout << "it should be fine\n";
        }
    }
    addUser(clientSocket);
    tables.at(tbl).addUser(clientSocket);
}
