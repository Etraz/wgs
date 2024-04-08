#include <iostream>
#include "../../../include/Edges/Actions/PlayerDrawsCardAction.hpp"

void PlayerDrawsCardAction::run(ComponentProvider &componentProvider) {
    auto cardHolder = componentProvider.getPlayingCardsDecks().getCard();
    auto & card = dynamic_cast<const PlayingCard &>(cardHolder->getCard());

    //OLD
    std::string message = (componentProvider.getNextPlayer() ? "Player" : "Dealer");
    message += " draws ";
    message += toString(card);
//    std::cout << message << std::endl;
    componentProvider.getConnectionComponent().sendMessage(message);

    componentProvider.getHandsComponent().addCardToPlayer(componentProvider.getNextPlayer(), std::move(cardHolder));
}