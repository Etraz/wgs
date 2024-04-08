#pragma once
#include "Component.hpp"

class ChipsComponent: public Component{
private:
    int owned, bet;
public:
    ChipsComponent(int);

    int getBet() const;

    int getOwned() const;

    void doubleBet();

    void newBet(int);

    void won();

    void returnBet();
};
