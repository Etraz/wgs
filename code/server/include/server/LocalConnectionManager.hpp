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
#include <map>


using PlayerAddress = int;


class LocalConnectionManager {

public:
    std::map<int, int> fds;
    int last = 1;

    LocalConnectionManager();

    void addUser(int fd);

    std::vector<PlayerAddress> getKeys();

    bool send(std::string s, PlayerAddress i = 0);

    int sendToAll(std::string s);

    std::string receiveFromUser(PlayerAddress i);
};

#endif //WGS_LOCALCONNECTIONMANAGER_HPP
