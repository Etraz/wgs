#include "../../../include/Edges/Actions/EndGameAction.hpp"

void EndGameAction::run(ComponentProvider &componentProvider) {
    componentProvider.setGameToContinue(false);
}