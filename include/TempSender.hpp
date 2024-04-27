#pragma once

#include "AbstractSendRec.hpp"

class TempSender : public AbstractSendRec {
private:

    int askForBet(int);

    int askForMove(std::string);


public:
    int fd = -1;

    explicit TempSender(int);

    std::string getMessage(std::string) override;

    std::string sendRec(std::string, PlayerAddress) override;

    void send(std::string, PlayerAddress) override;
};