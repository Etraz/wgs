#include "actions/common/EndGameAction.hpp"

void EndGameAction::run(ComponentProvider &componentProvider) {
    auto &connection = dynamic_cast<ConnectionComponent &>(componentProvider.getComponent("ConnectionComponent"));
    connection.sendBroadcast("PrintMessage:END GAME");
    componentProvider.setGameToContinue(false);
}