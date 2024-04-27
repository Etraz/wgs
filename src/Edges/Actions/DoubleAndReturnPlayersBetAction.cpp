#include "../../../include/Edges/Actions/DoubleAndReturnPlayersBetAction.hpp"

void DoubleAndReturnPlayersBetAction::run(ComponentProvider &componentProvider) {
    auto &connection = dynamic_cast<ConnectionComponent &>(componentProvider.getComponent("ConnectionComponent"));
    auto &chips = dynamic_cast<ChipsComponent &>(componentProvider.getComponent("ChipsComponent"));
    auto &players = dynamic_cast<PlayerComponent &>(componentProvider.getComponent("PlayersComponent"));

    connection.send("PrintMessage:YOU WON", players.getCurrentPlayer());
    chips.won(players.getCurrentPlayer());
}
