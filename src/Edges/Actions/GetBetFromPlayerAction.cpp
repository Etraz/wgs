#include "../../../include/Edges/Actions/GetBetFromPlayerAction.hpp"

void GetBetFromPlayerAction::run(ComponentProvider & componentProvider) {
    auto & chips = componentProvider.getChipsComponent();
    auto & connection = componentProvider.getConnectionComponent();
    std::string message = "AskBet:" + std::to_string(chips.getOwned());
    chips.newBet(std::stoi(connection.sendMessage(message)));
}