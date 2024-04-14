#pragma once

#include "../AbstractSendRec.hpp"
#include "Component.hpp"

class ConnectionComponent : public Component{
private:
    AbstractSendRec &connection;
public:
    explicit ConnectionComponent(AbstractSendRec &);

    std::string sendMessage(std::string);
};