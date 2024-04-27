#pragma once

#include "Condition.hpp"

class CurrentPlayerIsXCondition : public Condition {
private:
    const PlayerIndex x;
public:
    explicit CurrentPlayerIsXCondition(PlayerIndex);

    bool check(ComponentProvider &) override;
};