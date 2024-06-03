#include "actions/common/ShowPlayersHandAction.hpp"

void ShowPlayersHandAction::run(ComponentProvider &componentProvider) {
    auto &hands = dynamic_cast<HandsComponent &>(componentProvider.getComponent("HandsComponent"));
    hands.showPlayersCards(0);
}