#include <iostream>
#include "actions/common/PlayerDrawsCardAction.hpp"

PlayerDrawsCardAction::PlayerDrawsCardAction(bool isCardSecret): isCardSecret{isCardSecret} {

}


void PlayerDrawsCardAction::run(ComponentProvider &componentProvider) {
    auto &deck = dynamic_cast<CardDeck &>(componentProvider.getComponent("CardDeck"));
    auto &hands = dynamic_cast<HandsComponent &>(componentProvider.getComponent("HandsComponent"));
    auto &players = dynamic_cast<PlayerComponent &>(componentProvider.getComponent("PlayersComponent"));

    if(isCardSecret)
        hands.addSecretCardToPlayer(players.getCurrentPlayer(), std::move(deck.getCard()));
    else
        hands.addOpenCardToPlayer(players.getCurrentPlayer(), std::move(deck.getCard()));
}

