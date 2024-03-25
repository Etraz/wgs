#include "../../../include/Edges/Actions/SendMessageAction.hpp"

#include <utility>

SendMessageAction::SendMessageAction(std::string message) : message{std::move(message)} {}

void SendMessageAction::run(ComponentProvider &componentProvider) {
    componentProvider.getConnectionComponent().sendMessage(message);
}