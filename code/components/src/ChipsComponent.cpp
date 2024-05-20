#include "components/ChipsComponent.hpp"

ChipsComponent::ChipsComponent(const unsigned int numberOfPlayers) :
        numberOfPlayers{numberOfPlayers} {
    owned.reserve(numberOfPlayers + 1);
    for (size_t i = 0; i <= numberOfPlayers; i++)
        owned.push_back(std::make_shared<int>(1000));
    restart();
}

int ChipsComponent::getBet(PlayerIndex index) const {
    return bet[index];
}

int ChipsComponent::getOwned(PlayerIndex index) const {
    return *owned[index];
}

void ChipsComponent::doubleBet(PlayerIndex index) {
    *owned[index] -= bet[index];
    bet[index] += bet[index];
}

void ChipsComponent::newBet(PlayerIndex index, int newBet) {
    *owned[index] -= newBet;
    bet[index] = newBet;
}

void ChipsComponent::won(PlayerIndex index) {
    *owned[index] += 2 * bet[index];
    bet[index] = 0;
}

void ChipsComponent::returnBet(PlayerIndex index) {
    *owned[index] += bet[index];
    bet[index] = 0;
}

void ChipsComponent::returnHalfBet(PlayerIndex index) {
    *owned[index] += bet[index] / 2;
    bet[index] = 0;
}

void ChipsComponent::restart() {
    owned.resize(numberOfPlayers + 1);
    bet = std::vector<int>(numberOfPlayers + 1, 0);
}

void ChipsComponent::splitPlayer(PlayerIndex index) {
    *owned[index] -= bet[index];
    owned.push_back(owned[index]);
    bet.push_back(bet[index]);
}
