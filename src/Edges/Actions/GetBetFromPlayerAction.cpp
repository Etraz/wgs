#include "../../../include/Edges/Actions/GetBetFromPlayerAction.hpp"

void GetBetFromPlayerAction::run(ComponentProvider &componentProvider) {
    auto &chips = dynamic_cast<ChipsComponent &>(componentProvider.getComponent("ChipsComponent"));
    auto &connection = dynamic_cast<ConnectionComponent &>(componentProvider.getComponent("ConnectionComponent"));
    std::string message = "AskBet:" + std::to_string(chips.getOwned());
    chips.newBet(std::stoi(connection.sendMessage(message)));
}