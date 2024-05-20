#include "actions/blackjack/ShowDealersCardsAction.hpp"

void ShowDealersCardsAction::run(ComponentProvider &componentProvider) {
    auto &hands = dynamic_cast<HandsComponent &>(componentProvider.getComponent("HandsComponent"));
    hands.showPlayersCards(0);
}