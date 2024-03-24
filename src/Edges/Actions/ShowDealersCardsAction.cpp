#include "../../../include/Edges/Actions/ShowDealersCardsAction.hpp"

void ShowDealersCardsAction::run(ComponentProvider & componentProvider){
    for (auto & card : componentProvider.getHandsComponent().getDealersHand())
        card.setShown(true);
}