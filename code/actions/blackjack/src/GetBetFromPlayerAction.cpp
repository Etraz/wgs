#include "actions/blackjack/GetBetFromPlayerAction.hpp"

void GetBetFromPlayerAction::run(ComponentProvider &componentProvider) {
    auto &chips = dynamic_cast<ChipsComponent &>(componentProvider.getComponent("ChipsComponent"));
    auto &connection = dynamic_cast<ConnectionComponent &>(componentProvider.getComponent("ConnectionComponent"));
    auto &players = dynamic_cast<PlayerComponent &>(componentProvider.getComponent("PlayersComponent"));
    std::string message = "AskBet:" + std::to_string(chips.getOwned(players.getCurrentPlayer()));
    std::string response = connection.sendRec(message, players.getCurrentPlayer());
    chips.newBet(players.getCurrentPlayer(), std::stoi(response.substr(response.find(':') + 1)));
}