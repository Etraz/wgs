#include "../../include/Components/ChipsComponent.hpp"

ChipsComponent::ChipsComponent(int owned) : owned{owned}, bet{0} {}

int ChipsComponent::getBet() const {
    return bet;
}

int ChipsComponent::getOwned() const {
    return owned;
}

void ChipsComponent::doubleBet() {
    owned -= bet;
    bet += bet;
}

void ChipsComponent::newBet(int bet) {
    this->owned -= bet;
    this->bet = bet;
}

void ChipsComponent::won() {
    owned += 2 * bet;
    bet = 0;
}

void ChipsComponent::returnBet() {
    owned += bet;
    bet = 0;
}
