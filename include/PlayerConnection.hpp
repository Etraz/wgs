#pragma once

#include <string>

class PlayerConnection {
private:
    int askForBet(int);

    int askForMove(std::string);

public:
    std::string getMessage(std::string);
};