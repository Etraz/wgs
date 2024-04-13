#pragma once

#include <string>

class PlayerConnection {
private:
    int askForBet(int);
    int askForMove(std::string);
public:
    virtual std::string getMessage(std::string);
};