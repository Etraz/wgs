#include "../../../include/Edges/Conditions/PlayerCanBetCondition.hpp"

bool PlayerCanBetCondition::check(ComponentProvider &componentProvider) {
    auto &chips = dynamic_cast<ChipsComponent &>(componentProvider.getComponent("ChipsComponent"));
    auto &players = dynamic_cast<PlayerComponent &>(componentProvider.getComponent("PlayersComponent"));

    return (chips.getOwned(players.getCurrentPlayer()) > 0);
}