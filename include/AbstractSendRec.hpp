#pragma once

#include <string>

using PlayerAddress = unsigned long long;

class AbstractSendRec {
public:
    // to be removed
    virtual std::string getMessage(std::string) = 0;

    virtual std::string sendRec(std::string, PlayerAddress) = 0;

    virtual void send(std::string, PlayerAddress) = 0;
};