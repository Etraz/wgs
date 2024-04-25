#pragma once

#include <string>

class AbstractSendRec{
public:
    virtual std::string getMessage(std::string) = 0;
    // Proposition of new methods
    // virtual std::string sendRec(std::string mess, PlayerAddress target) = 0;
    // virtual void send(std::string mess, PlayerAddress target) = 0;
    // PlayerAddress should be alias of some numerical type and all possible addresses shall be known
    // before starting the game
};