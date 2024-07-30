#include "components/BridgeAuctionComponent.hpp"

bool BridgeAuctionComponent::isAuctionToContinue() const {
    if (calls.size() < 4)
        return true;
    for (auto i = calls.size() - 3; i < calls.size(); i++)
        if (calls[i].second.getType() != passCall)
            return true;
    return false;
}


BridgeAuctionComponent::BridgeAuctionComponent() {
    restart();
}

void BridgeAuctionComponent::addNextCall(const PlayerIndex playerIndex, BridgeCall call) {
    calls.emplace_back(playerIndex, call);
}

void BridgeAuctionComponent::restart() {
    calls.clear();
}

std::pair<PlayerIndex, BridgeCall> BridgeAuctionComponent::getLastNormalCall() const {
    for (auto ite = calls.rbegin(); ite != calls.rend(); ite++) // NOLINT(modernize-loop-convert)
        if (ite->second.getType() == normalCall)
            return *ite;
    return std::make_pair(PlayerIndex{9}, BridgeCall{0, noTrump, normalCall});
}

bool BridgeAuctionComponent::canNextBeDouble() const {
    if (calls.empty())
        return false;
    auto ite = calls.rbegin();
    auto type = ite->second.getType();
    ite++;
    if (type == normalCall)
        return true;
    if (type == doubleCall or type == reDoubleCall or ite == calls.rend())
        return false;
    type = ite->second.getType();
    ite++;
    if (type != passCall or ite == calls.rend())
        return false;
    type = ite->second.getType();
    return (type == normalCall);
}

bool BridgeAuctionComponent::canNextBeReDouble() const {
    if (calls.empty())
        return false;
    auto ite = calls.rbegin();
    auto type = ite->second.getType();
    ite++;
    if (type == doubleCall)
        return true;
    if (type == normalCall or type == reDoubleCall or ite == calls.rend())
        return false;
    type = ite->second.getType();
    ite++;
    if (type != passCall or ite == calls.rend())
        return false;
    type = ite->second.getType();
    return (type == doubleCall);
}

PlayerIndex BridgeAuctionComponent::getPlayerThatWillBePlaying() const {
    auto lastCall = getLastNormalCall();

    for (size_t i = (lastCall.first % 2); i < calls.size(); i++)
        if (calls[i].second.getSuite() == lastCall.second.getSuite())
            return (i % 2);
    return lastCall.first;
}
