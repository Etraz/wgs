#include <iostream>
#include "../../../include/Edges/Actions/PlayerWonAction.hpp"

void PlayerWonAction::run(ComponentProvider &componentProvider) {
    auto & connection = dynamic_cast<ConnectionComponent &>(componentProvider.getComponent("ConnectionComponent"));
    auto & chips = dynamic_cast<ChipsComponent &>(componentProvider.getComponent("ChipsComponent"));
    connection.sendMessage("YOU WON\n");
    chips.won();
}
