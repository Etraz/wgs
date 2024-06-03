#include "conditions/bridge/AuctionToContinueCondition.hpp"

bool AuctionToContinueCondition::check(ComponentProvider &componentProvider) {
    auto &auction = dynamic_cast<BridgeAuctionComponent &>(componentProvider.getComponent("AuctionComponent"));
    return auction.isAuctionToContinue();
}
