#pragma once

#include "edges/Condition.hpp"

class CurrentPlayerIsXCondition : public Condition {
private:
    const PlayerIndex x;
public:
    explicit CurrentPlayerIsXCondition(PlayerIndex);

    bool check(ComponentProvider &) override;
};