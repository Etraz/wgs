#include "../../../include/Edges/Conditions/PlayerCanDoubleBetCondition.hpp"

bool PlayerCanDoubleBetCondition::check(ComponentProvider &componentProvider) {
    auto &chips = dynamic_cast<ChipsComponent &>(componentProvider.getComponent("ChipsComponent"));
    auto &players = dynamic_cast<PlayerComponent &>(componentProvider.getComponent("PlayersComponent"));

    return chips.getBet(players.getCurrentPlayer()) <= chips.getOwned(players.getCurrentPlayer());
}