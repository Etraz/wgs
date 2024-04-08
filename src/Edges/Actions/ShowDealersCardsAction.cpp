#include "../../../include/Edges/Actions/ShowDealersCardsAction.hpp"

void ShowDealersCardsAction::run(ComponentProvider &componentProvider) {
    componentProvider.getHandsComponent().showPlayersCards(0);
}