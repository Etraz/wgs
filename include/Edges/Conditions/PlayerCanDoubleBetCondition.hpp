#pragma once
#include "Condition.hpp"

class PlayerCanDoubleBetCondition : public Condition {
public:
    bool check(ComponentProvider &) override;
};