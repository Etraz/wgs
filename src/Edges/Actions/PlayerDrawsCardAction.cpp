#include <iostream>
#include "../../../include/Edges/Actions/PlayerDrawsCardAction.hpp"

void PlayerDrawsCardAction::run(ComponentProvider &componentProvider) {
    auto &deck = dynamic_cast<DeckComponent &>(componentProvider.getComponent("DeckComponent"));
    auto &hands = dynamic_cast<HandsComponent &>(componentProvider.getComponent("HandsComponent"));
    auto &players = dynamic_cast<PlayerComponent &>(componentProvider.getComponent("PlayersComponent"));

    hands.addCardToPlayer(players.getCurrentPlayer(), std::move(deck.getCard()));
}