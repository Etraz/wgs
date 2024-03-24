#include "../../../include/Edges/Actions/PlayerDrawsReversedCardAction.hpp"

void PlayerDrawsReversedCardAction::run(ComponentProvider & componentProvider) {
    auto card = componentProvider.getPlayingCardsDecks().getCard();
    card.setShown(false);
    if (componentProvider.isPlayerNext())
        componentProvider.getHandsComponent().getPlayersHand().push_back(card);
    else
        componentProvider.getHandsComponent().getDealersHand().push_back(card);
    std::string message = (componentProvider.isPlayerNext() ? "Dealer" : "Player");
    message += " draws ";
    message += toString(card);
    componentProvider.getConnectionComponent().sendMessage(message);
}