#include "actions/bridge/SendAfterGameInfoAction.hpp"

void SendAfterGameInfoAction::run(ComponentProvider &componentProvider) {
    auto &tricks = dynamic_cast<BridgeTricksComponent &>(componentProvider.getComponent("TricksComponent"));
    auto &connection = dynamic_cast<ConnectionComponent &>(componentProvider.getComponent("ConnectionComponent"));

    bool contractWon = tricks.isContractFulfiled();
    PlayerIndex declaringPlayer = tricks.getDeclaringPlayer();

    for (PlayerIndex playerIndex = 0; playerIndex < 4; playerIndex++){
        // This is kinda stupid but it should work
        if (contractWon == ((declaringPlayer % 2) == (playerIndex % 2)))
            connection.send("YOU WON", playerIndex);
        else
            connection.send("YOU LOST", playerIndex);
    }

}
