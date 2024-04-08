#pragma once

#include "../PlayerConnection.hpp"
#include "Component.hpp"
#include "../Server/LocalConnectionManager.hpp"

class ConnectionComponent : public Component{
private:
    PlayerConnection &connection;
    LocalConnectionManager lcm;
public:
    ConnectionComponent(PlayerConnection &);

    std::string sendMessage(std::string);
};