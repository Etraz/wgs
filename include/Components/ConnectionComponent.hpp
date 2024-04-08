#pragma once

#include "../PlayerConnection.hpp"
#include "Component.hpp"

class ConnectionComponent : public Component{
private:
    PlayerConnection &connection;
public:
    ConnectionComponent(PlayerConnection &);

    std::string sendMessage(std::string);
};