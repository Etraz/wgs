#pragma once

#include "edges/Condition.hpp"

class PlayerCanDoubleBetCondition : public Condition {
public:
    bool check(ComponentProvider &) override;
};