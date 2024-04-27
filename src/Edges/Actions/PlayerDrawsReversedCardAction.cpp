#include "../../../include/Edges/Actions/PlayerDrawsReversedCardAction.hpp"
#include <iostream>

void PlayerDrawsReversedCardAction::run(ComponentProvider &componentProvider) {
    auto & deck = dynamic_cast<DeckComponent &>(componentProvider.getComponent("DeckComponent"));
    auto & hands = dynamic_cast<HandsComponent &>(componentProvider.getComponent("HandsComponent"));
    auto & players = dynamic_cast<PlayerComponent &>(componentProvider.getComponent("PlayersComponent"));
    auto cardHolder = deck.getCard();

    cardHolder->reverseCard();
    hands.addCardToPlayer(players.getCurrentPlayer(), std::move(cardHolder));
}