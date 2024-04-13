#include <iostream>
#include "../../../include/Edges/Actions/PlayerTiedAction.hpp"

void PlayerTiedAction::run(ComponentProvider &componentProvider) {
    auto & connection = dynamic_cast<ConnectionComponent &>(componentProvider.getComponent("ConnectionComponent"));
    auto & chips = dynamic_cast<ChipsComponent &>(componentProvider.getComponent("ChipsComponent"));
    connection.sendMessage("YOU TIED\n");
    chips.returnBet();
}