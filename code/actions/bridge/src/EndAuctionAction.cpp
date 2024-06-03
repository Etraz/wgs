#include "actions/bridge/EndAuctionAction.hpp"

void EndAuctionAction::run(ComponentProvider &componentProvider) {
    auto &auction = dynamic_cast<BridgeAuctionComponent &>(componentProvider.getComponent("AuctionComponent"));
    auto &tricks = dynamic_cast<BridgeTricksComponent &>(componentProvider.getComponent("TricksComponent"));
    auto &players = dynamic_cast<PlayerComponent &>(componentProvider.getComponent("PlayersComponent"));
    auto &connection = dynamic_cast<ConnectionComponent &>(componentProvider.getComponent("ConnectionComponent"));

    auto endingCallInfo = auction.getLastNormalCall();
    tricks.setContractAndDeclaringPlayer(endingCallInfo.second, endingCallInfo.first);

    while (players.getCurrentPlayer() != endingCallInfo.first)
        players.nextPlayer();

    std::string mess = "ActionBridgeAuctionEnd:"
                       + std::to_string(endingCallInfo.second.getNumber()) + ';'
                       + ToString(endingCallInfo.second.getSuite()) + ';'
                       + std::to_string(endingCallInfo.first);

    connection.sendBroadcast(mess);

}
