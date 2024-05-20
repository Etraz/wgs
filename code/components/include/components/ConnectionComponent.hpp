#pragma once

#include "connection/AbstractSendRec.hpp"
#include "Component.hpp"
#include <vector>
#include <memory>

class ComponentProvider;

class ConnectionComponent : public Component {
private:
    std::unique_ptr<AbstractSendRec> connection;
    std::vector<PlayerAddress> addresses;
    std::vector<bool> sendBroadcastTo;
    const unsigned int numberOfPlayers;
public:
    explicit ConnectionComponent(unsigned int, std::unique_ptr<AbstractSendRec> &&, std::vector<PlayerAddress> &&);

    std::string sendRec(std::string, PlayerIndex);

    void send(std::string, PlayerIndex);

    void sendBroadcast(const std::string &);

    void splitConnection(PlayerIndex);

    void restart();
};
