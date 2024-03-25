#include "../../../include/Edges/Actions/EndGameAction.hpp"

void EndGameAction::run(ComponentProvider &componentProvider) {
    componentProvider.getConnectionComponent().sendMessage("END GAME\n");
    componentProvider.setGameToContinue(false);
}