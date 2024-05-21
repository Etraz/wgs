#include "actions/common/GoToNextPlayerAction.hpp"

void GoToNextPlayerAction::run(ComponentProvider &componentProvider) {
    auto &players = dynamic_cast<PlayerComponent &>(componentProvider.getComponent("PlayersComponent"));
    players.nextPlayer();
}