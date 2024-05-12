#include <iostream>
#include <utility>
#include "../../include/Components/PlayerComponent.hpp"
#include "../../include/Components/ComponentProvider.hpp"

PlayerComponent::PlayerComponent(std::shared_ptr<ComponentProvider> componentProvider,
                                 unsigned int numberOfPlayers) :
        componentProvider{std::move(componentProvider)},
        numberOfPlayers{numberOfPlayers} {
    restart();
}

void PlayerComponent::restart() {
    players.clear();
    for (PlayerIndex i = 0; i <= numberOfPlayers; i++)
        players.push_back(i);
    maxPlayerIndex = numberOfPlayers;
    nextPlayer();
}

void PlayerComponent::split() {
    auto &hands = dynamic_cast<HandsComponent &>(componentProvider->getComponent("HandsComponent"));
    auto &connection = dynamic_cast<ConnectionComponent &>(componentProvider->getComponent("ConnectionComponent"));
    auto &chips = dynamic_cast<ChipsComponent &>(componentProvider->getComponent("ChipsComponent"));
    auto front = players.front();
    ++maxPlayerIndex;
    players.pop_front();
    players.push_front(maxPlayerIndex);
    players.push_front(front);
    connection.splitConnection(front);
    chips.splitPlayer(front);
    hands.splitHand(front);
}

void PlayerComponent::nextPlayer() {
    players.push_back(players.front());
    players.pop_front();
}

PlayerIndex PlayerComponent::getCurrentPlayer() {
    return players.front();
}
