#include "actions/bridge/BridgeRestartAction.hpp"

void BridgeRestartAction::run(ComponentProvider &componentProvider) {
    auto &hands = dynamic_cast<HandsComponent &>(componentProvider.getComponent("HandsComponent"));
    auto &players = dynamic_cast<PlayerComponent &>(componentProvider.getComponent("PlayersComponent"));
    auto &deck = dynamic_cast<CardDeck &>(componentProvider.getComponent("CardDeck"));
    auto &tricks = dynamic_cast<BridgeTricksComponent &>(componentProvider.getComponent("TricksComponent"));
    auto &auction = dynamic_cast<BridgeAuctionComponent &>(componentProvider.getComponent("AuctionComponent"));

    hands.restart();
    players.restart();
    deck.restart();
    tricks.restart();
    auction.restart();
}
