#include "../../../include/Edges/Actions/DoublePlayersBetAction.hpp"

void DoublePlayersBetAction::run(ComponentProvider &componentProvider) {
    auto & chips = dynamic_cast<ChipsComponent &>(componentProvider.getComponent("ChipsComponent"));
    auto & players = dynamic_cast<PlayerComponent &>(componentProvider.getComponent("PlayersComponent"));

    chips.doubleBet(players.getCurrentPlayer());
}