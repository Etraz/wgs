#pragma once

#include "../PlayerConnection.hpp"

class ConnectionComponent {
private:
    PlayerConnection &connection;
public:
    ConnectionComponent(PlayerConnection &);

    std::string sendMessage(std::string);
};