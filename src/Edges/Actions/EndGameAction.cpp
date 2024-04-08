#include <iostream>
#include "../../../include/Edges/Actions/EndGameAction.hpp"

void EndGameAction::run(ComponentProvider &componentProvider) {
    std::cout << "END GAME\n";
    componentProvider.setGameToContinue(false);
}