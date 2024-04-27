#pragma once

#include "AbstractSendRec.hpp"

class PlayersConnection : public AbstractSendRec {
private:
    static std::string askForBet(int);

    static std::string askForMove(const std::string &);

public:
    std::string getMessage(std::string) override;

    std::string sendRec(std::string, PlayerAddress) override;

    void send(std::string, PlayerAddress) override;
};