#pragma once

class ChipsComponent{
private:
    int owned, bet;
public:
    ChipsComponent(int);
    int getBet();
    int getOwned();
    void doubleBet();
    void newBet(int);
    void won();
};
