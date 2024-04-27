#include "../../../include/Edges/Actions/ReturnPlayerBetAction.hpp"

void ReturnPlayerBetAction::run(ComponentProvider &componentProvider) {
    auto &connection = dynamic_cast<ConnectionComponent &>(componentProvider.getComponent("ConnectionComponent"));
    auto &chips = dynamic_cast<ChipsComponent &>(componentProvider.getComponent("ChipsComponent"));
    auto &players = dynamic_cast<PlayerComponent &>(componentProvider.getComponent("PlayersComponent"));

    connection.send("YOU TIED", players.getCurrentPlayer());
    chips.returnBet(players.getCurrentPlayer());
}