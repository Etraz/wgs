#pragma once

#include <string>

class PlayerConnection {
private:

    int askForBet(int);

    int askForMove(std::string);



public:
    int fd=-1;
    std::string getMessage(std::string);
};