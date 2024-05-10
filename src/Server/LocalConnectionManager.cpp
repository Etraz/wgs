//
// Created by przem on 07.04.2024.
//
#include <iostream>
#include <sys/socket.h>
#include <thread>
#include <vector>
#include "../../include/Server/LocalConnectionManager.hpp"


bool LocalConnectionManager::send(std::string s, int i) {
    if (::send(fds.at(i), s.c_str(), s.size(), 0) == -1) {
        return false;
    }
    return true;
}

void LocalConnectionManager::addUser(int fd) {
    fds.emplace_back(fd);
}

std::string LocalConnectionManager::receiveFromUser(int i) {

    char buf[2048];
    int r = recv(fds.at(i), buf, sizeof(buf), 0);
    std::string s = buf;
    s.resize(r);
    return s;
}

int LocalConnectionManager::sendToAll(std::string s) {
    for (auto i: fds) {
        ::send(i, s.c_str(), s.size(), 0);
    }
    return 0;
}

LocalConnectionManager::LocalConnectionManager() {
    this->fds = {};
}
