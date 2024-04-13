#include <iostream>
#include "../../../include/Edges/Actions/EndGameAction.hpp"

void EndGameAction::run(ComponentProvider &componentProvider) {
//    std::cout << "END GAME\n";
    auto & connection = dynamic_cast<ConnectionComponent &>(componentProvider.getComponent("ConnectionComponent"));
    connection.sendMessage("END GAME\n");
    componentProvider.setGameToContinue(false);
}