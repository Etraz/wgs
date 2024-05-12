#pragma once

#include <string>

using PlayerAddress = int;

class AbstractSendRec {
public:
    virtual std::string sendRec(std::string, PlayerAddress) = 0;

    virtual void send(std::string, PlayerAddress) = 0;

    virtual ~AbstractSendRec() = default;
};