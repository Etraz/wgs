#include "../../../include/Edges/Actions/PlayerTiedAction.hpp"

void PlayerTiedAction::run(ComponentProvider &componentProvider) {
    componentProvider.getConnectionComponent().sendMessage("YOU TIED\n");
    componentProvider.getChipsComponent().returnBet();
}