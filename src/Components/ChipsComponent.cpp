#include "../../include/Components/ChipsComponent.hpp"

ChipsComponent::ChipsComponent(int owned):owned{owned}, bet{0} {}
int ChipsComponent::getBet(){
    return bet;
}
int ChipsComponent::getOwned(){
    return owned;
}

void ChipsComponent::doubleBet() {
    owned -= bet;
    bet += bet;
}

void ChipsComponent::newBet(int bet){
    this -> bet = bet;
}
void ChipsComponent::won(){
    owned += 2 * bet;
    bet = 0;
}
