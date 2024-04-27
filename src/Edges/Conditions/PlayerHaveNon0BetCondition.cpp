#include "../../../include/Edges/Conditions/PlayerHaveNon0BetCondition.hpp"

bool PlayerHaveNon0BetCondition::check(ComponentProvider &componentProvider) {
    auto &chips = dynamic_cast<ChipsComponent &>(componentProvider.getComponent("ChipsComponent"));
    auto &players = dynamic_cast<PlayerComponent &>(componentProvider.getComponent("PlayersComponent"));

    return chips.getBet(players.getCurrentPlayer()) != 0;
}