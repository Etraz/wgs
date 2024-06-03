#pragma once

#include "AbstractSendRec.hpp"

class LocalSendRec : public AbstractSendRec {
private:
    static std::string askForBet(int);

    static std::string askForMove(const std::string &);

    static std::string askForCardToPlay(const std::string &);


public:
    std::string sendRec(std::string, PlayerAddress) override;

    void send(std::string, PlayerAddress) override;

};