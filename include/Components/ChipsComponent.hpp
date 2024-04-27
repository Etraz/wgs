#pragma once

#include "Component.hpp"
#include <vector>
#include <memory>

class ComponentProvider;

class ChipsComponent : public Component {
private:
    std::vector<std::shared_ptr<int>> owned;
    std::vector<int> bet;
    const unsigned int numberOfPlayers;

public:
    explicit ChipsComponent(unsigned int);

    [[nodiscard]] int getBet(PlayerIndex) const;

    [[nodiscard]] int getOwned(PlayerIndex) const;

    void doubleBet(PlayerIndex);

    void newBet(PlayerIndex, int);

    void won(PlayerIndex);

    void returnBet(PlayerIndex);

    void returnHalfBet(PlayerIndex);

    void splitPlayer(PlayerIndex);

    void restart();
};
