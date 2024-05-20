#include "actions/blackjack/ReturnHalfOfPlayerBetAction.hpp"

void ReturnHalfOfPlayerBetAction::run(ComponentProvider &componentProvider) {
    auto &chips = dynamic_cast<ChipsComponent &>(componentProvider.getComponent("ChipsComponent"));
    auto &players = dynamic_cast<PlayerComponent &>(componentProvider.getComponent("PlayersComponent"));
    chips.returnHalfBet(players.getCurrentPlayer());
}