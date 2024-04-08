#include <iostream>
#include "../../../include/Edges/Actions/PlayerTiedAction.hpp"

void PlayerTiedAction::run(ComponentProvider &componentProvider) {
    std::cout << "YOU TIED\n";
    componentProvider.getChipsComponent().returnBet();
}