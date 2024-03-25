#include "../../../include/Edges/Actions/SendHandsAction.hpp"

void SendHandsAction::run(ComponentProvider &componentProvider) {
    std::string message = "YOUR HAND: ";
    message += toString(componentProvider.getHandsComponent().getPlayersHand());
    message += "\nDEALERS HAND: ";
    message += toString(componentProvider.getHandsComponent().getDealersHand());
    componentProvider.getConnectionComponent().sendMessage(message);
}