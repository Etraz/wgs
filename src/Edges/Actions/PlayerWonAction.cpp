#include <iostream>
#include "../../../include/Edges/Actions/PlayerWonAction.hpp"

void PlayerWonAction::run(ComponentProvider &componentProvider) {
    std::cout << "YOU WON\n";
    componentProvider.getChipsComponent().won();
}
