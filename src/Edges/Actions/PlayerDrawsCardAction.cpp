#include "../../../include/Edges/Actions/PlayerDrawsCardAction.hpp"

void PlayerDrawsCardAction::run(ComponentProvider &componentProvider) {
    auto card = componentProvider.getPlayingCardsDecks().getCard();
    if (componentProvider.isPlayerNext())
        componentProvider.getHandsComponent().getPlayersHand().push_back(card);
    else
        componentProvider.getHandsComponent().getDealersHand().push_back(card);
    std::string message = (componentProvider.isPlayerNext() ? "Player" : "Dealer");
    message += " draws ";
    message += toString(card);
    componentProvider.getConnectionComponent().sendMessage(message);
}