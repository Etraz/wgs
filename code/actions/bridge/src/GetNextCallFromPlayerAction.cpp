#include "actions/bridge/GetNextCallFromPlayerAction.hpp"

void GetNextCallFromPlayerAction::run(ComponentProvider &componentProvider) {
    auto &auction = dynamic_cast<BridgeAuctionComponent &>(componentProvider.getComponent("AuctionComponent"));
    auto &connection = dynamic_cast<ConnectionComponent &>(componentProvider.getComponent("ConnectionComponent"));
    auto &players = dynamic_cast<PlayerComponent &>(componentProvider.getComponent("PlayersComponent"));

    // AskBridgeCall:[lastCallNumber];[lastCallSuite];[canDouble];[canReDouble]
    auto lastCallInfo = auction.getLastNormalCall();
    bool canDouble = auction.canNextBeDouble(), canReDouble = auction.canNextBeReDouble();
    std::string mess = "AskBridgeCall:" + std::to_string(lastCallInfo.second.getNumber()) + ';'
                       + std::to_string(static_cast<int>(lastCallInfo.second.getSuite())) + ';'
                       + (canDouble ? '1' : '0') + ';' + (canReDouble ? '1' : '0');

    // AskBridgeCallResp:[nextCallNumber];[nextCallSuite];[nextCallType]
    std::string resp = connection.sendRec(mess, players.getCurrentPlayer());
    BridgeCall nextCall = BridgeCall(resp.substr(resp.find(':') + 1));
    auction.addNextCall(players.getCurrentPlayer(), nextCall);

    mess = "ActionBridgeCall:" + std::to_string(nextCall.getNumber()) + ';'
           + std::to_string(static_cast<int>(nextCall.getSuite())) + ';'
           + std::to_string(static_cast<int>(nextCall.getType())) + ';'
           + std::to_string(players.getCurrentPlayer());

    connection.sendBroadcast(mess);
}
