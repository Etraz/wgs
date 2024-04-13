#include "../../../include/Edges/Actions/PlayerDrawsReversedCardAction.hpp"
#include <iostream>

void PlayerDrawsReversedCardAction::run(ComponentProvider &componentProvider) {
    auto & deck = dynamic_cast<DeckComponent &>(componentProvider.getComponent("DeckComponent"));
    auto & hands = dynamic_cast<HandsComponent &>(componentProvider.getComponent("HandsComponent"));
    auto & connection = dynamic_cast<ConnectionComponent &>(componentProvider.getComponent("ConnectionComponent"));
    auto cardHolder = deck.getCard();
    cardHolder->reverseCard();
    auto & card = dynamic_cast<const PlayingCard &>(cardHolder->getCard());

    //OLD
    std::string message = (componentProvider.getNextPlayer() ? "Player" : "Dealer");
    message += " draws ";
    message += toString(card);
//    std::cout << message << std::endl;
   connection.sendMessage(message);

    hands.addCardToPlayer(componentProvider.getNextPlayer(), std::move(cardHolder));
}