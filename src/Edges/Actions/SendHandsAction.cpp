#include "../../../include/Edges/Actions/SendHandsAction.hpp"

void SendHandsAction::run(ComponentProvider &componentProvider) {
    auto & hands = dynamic_cast<HandsComponent &>(componentProvider.getComponent("HandsComponent"));
    auto & connection = dynamic_cast<ConnectionComponent &>(componentProvider.getComponent("ConnectionComponent"));
    std::string message = "YOUR HAND: ";
    message += toString(hands.getPlayersHand());
    message += "\nDEALERS HAND: ";
    message += toString(hands.getDealersHand());
    connection.sendMessage(message);
}