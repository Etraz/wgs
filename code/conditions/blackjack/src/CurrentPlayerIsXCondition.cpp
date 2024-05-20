#include "conditions/blackjack/CurrentPlayerIsXCondition.hpp"

CurrentPlayerIsXCondition::CurrentPlayerIsXCondition(PlayerIndex x) : x{x} {}

bool CurrentPlayerIsXCondition::check(ComponentProvider &componentProvider) {
    auto &players = dynamic_cast<PlayerComponent &>(componentProvider.getComponent("PlayersComponent"));

    return players.getCurrentPlayer() == x;
}
