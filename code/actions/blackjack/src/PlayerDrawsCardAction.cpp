#include <iostream>
#include "actions/blackjack/PlayerDrawsCardAction.hpp"

void PlayerDrawsCardAction::run(ComponentProvider &componentProvider) {
    auto &deck = dynamic_cast<CardDeck &>(componentProvider.getComponent("CardDeck"));
    auto &hands = dynamic_cast<HandsComponent &>(componentProvider.getComponent("HandsComponent"));
    auto &players = dynamic_cast<PlayerComponent &>(componentProvider.getComponent("PlayersComponent"));

    hands.addCardToPlayer(players.getCurrentPlayer(), std::move(deck.getCard()));
}