#include "components/BridgeTricksComponent.hpp"

void BridgeTricksComponent::setContractAndDeclaringPlayer(
        const BridgeCall &bridgeCall,
        const PlayerIndex &playerIndex) {
    contract = bridgeCall;
    declaringPlayer = playerIndex;
    setTrickStartingPlayer(declaringPlayer);
}

BridgeTricksComponent::BridgeTricksComponent() {
    restart();
}

void BridgeTricksComponent::playerWonTrick(const PlayerIndex &playerIndex) {
    tricks[playerIndex]++;
}

bool BridgeTricksComponent::isContractFulfiled() const {
    PlayerIndex parter = (declaringPlayer + 2) % 4;
    return contract.getNumber() + 6 <= tricks[declaringPlayer] + tricks[parter];
}

void BridgeTricksComponent::restart() {
    contract = BridgeCall{0, noTrump, passCall};

}

PlayerIndex BridgeTricksComponent::getTrickStartingPlayer() const {
    return trickStartingPlayer;
}

void BridgeTricksComponent::setTrickStartingPlayer(PlayerIndex playerIndex) {
    trickStartingPlayer = playerIndex;
}

PlayingCardColor BridgeTricksComponent::getContractsColor() const {
    return contract.getSuite();
}

PlayerIndex BridgeTricksComponent::getDeclaringPlayer() const {
    return declaringPlayer;
}
