#include "../../../include/Edges/Actions/PlayerSplitsAction.hpp"

void PlayerSplitsAction::run(ComponentProvider &componentProvider){
    auto & players = dynamic_cast<PlayerComponent &>(componentProvider.getComponent("PlayersComponent"));
    players.split();
}