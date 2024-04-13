#pragma once
#include "PlayerConnection.hpp"

class TempSender : public PlayerConnection {
private:

    int askForBet(int);

    int askForMove(std::string);



public:
    int fd=-1;
    explicit TempSender(int);

    std::string getMessage(std::string) override;
};