//
// Created by przem on 07.04.2024.
//
//
// This class is responsible for comunications during game process.
// It borrows sockets from ConnectionManager
// Currently everything is under one local manager
//


#ifndef WGS_LOCALCONNECTIONMANAGER_HPP
#define WGS_LOCALCONNECTIONMANAGER_HPP

#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <vector>

class LocalConnectionManager {

public:
    std::vector<int> fds;

    LocalConnectionManager();

    void addUser(int fd);

    bool send(std::string s, int i = 0);

    int sendToAll(std::string s);

    std::string receiveFromUser(int i);
};

#endif //WGS_LOCALCONNECTIONMANAGER_HPP
