#pragma once

#include "Component.hpp"
#include <vector>
#include <memory>
#include "components/cards/BridgeCall.hpp"

class BridgeAuctionComponent : public Component {
private:
    std::vector<std::pair<PlayerIndex, BridgeCall>> calls;
public:
    BridgeAuctionComponent();

    [[nodiscard]] bool isAuctionToContinue() const;

    void addNextCall(PlayerIndex, BridgeCall);

    [[nodiscard]] std::pair<PlayerIndex, BridgeCall> getLastNormalCall() const;

    [[nodiscard]] bool canNextBeDouble() const;

    [[nodiscard]] bool canNextBeReDouble() const;

    [[nodiscard]] PlayerIndex getPlayerThatWillBePlaying() const;

    void restart();
};