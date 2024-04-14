#pragma once

#include "AbstractSendRec.hpp"

class PlayerConnection : public AbstractSendRec{
private:
    int askForBet(int);
    int askForMove(std::string);
public:
    std::string getMessage(std::string) override;
};