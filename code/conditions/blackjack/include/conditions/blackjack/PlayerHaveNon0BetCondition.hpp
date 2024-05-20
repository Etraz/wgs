#pragma once

#include "edges/Condition.hpp"

class PlayerHaveNon0BetCondition : public Condition {
    bool check(ComponentProvider &) override;
};
