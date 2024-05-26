#pragma once
#include "components/Component.hpp"
#include "components/cards/BridgeCall.hpp"

class BridgeTricksComponent : public Component{
private:
    std::vector<int> tricks;
    BridgeCall contract{0, noTrump, passCall};
    PlayerIndex declaringPlayer{}, trickStartingPlayer;
public:
    BridgeTricksComponent();

    void setContractAndDeclaringPlayer(const BridgeCall &, const PlayerIndex &);
    void setTrickStartingPlayer(PlayerIndex trickStartingPlayer);
    void playerWonTrick(const PlayerIndex &);
    void goToNextTrick();
    void restart();

    [[nodiscard]] PlayerIndex getTrickStartingPlayer() const;
    [[nodiscard]] bool isContractFulfiled() const;
    [[nodiscard]] PlayingCardColor getContractsColor() const;

    PlayerIndex getDeclaringPlayer() const;
};

