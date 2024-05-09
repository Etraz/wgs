#pragma once

#include "../AbstractSendRec.hpp"
#include "Component.hpp"
#include <vector>

class ComponentProvider;

class ConnectionComponent : public Component {
private:
    AbstractSendRec &connection;
    std::vector<PlayerAddress> addresses;
    std::vector<bool> sendBroadcastTo;
    const unsigned int numberOfPlayers;
public:
    explicit ConnectionComponent(unsigned int, AbstractSendRec &);

    std::string sendRec(std::string, PlayerIndex);

    void send(std::string, PlayerIndex);

    void sendBroadcast(const std::string &);

    void splitConnection(PlayerIndex);

    void restart();
};
