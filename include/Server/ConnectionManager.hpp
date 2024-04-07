//
// Created by przem on 07.04.2024.
//
//
// This class connects clients to the server and then
// passes the sockets to the Local Connection Managers.
// It also starts/closes the server and saves the data
// (might be moved to another class)

#ifndef WGS_CONNECTIONMANAGER_HPP
#define WGS_CONNECTIONMANAGER_HPP
#include "LocalConnectionManager.hpp"
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>

class ConnectionManager {
    std::vector<LocalConnectionManager> tables;
    std::vector<int> fds;
    struct sockaddr_in serverAddr;
    int serverSocket;

public:
    ConnectionManager();

    bool stoppage;

    void addUser(int fd);
    void addTable();
    void loopAdd();
    bool startup(int port);
    void close();
    LocalConnectionManager& getTable(int index);
    void addUserTo(int index, int tbl);
    void addUserToTemporary(int tbl);
};


#endif //WGS_CONNECTIONMANAGER_HPP
