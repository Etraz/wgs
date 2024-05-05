#include "../../../include/Edges/Actions/SendMessageAction.hpp"

#include <utility>

SendMessageAction::SendMessageAction(std::string message) : message{std::move(message)} {}

void SendMessageAction::run(ComponentProvider &componentProvider) {
    auto &connection = dynamic_cast<ConnectionComponent &>(componentProvider.getComponent("ConnectionComponent"));
    auto &players = dynamic_cast<PlayerComponent &>(componentProvider.getComponent("PlayersComponent"));
    connection.send("PrintMessage:" + message, players.getCurrentPlayer());
}