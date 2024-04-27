#pragma once

#include "Condition.hpp"

class PlayerHaveNon0BetCondition : public Condition {
    bool check(ComponentProvider &) override;
};
