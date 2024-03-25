#pragma once

#include "Condition.hpp"

class PlayerCanBetCondition : public Condition {
public:
    bool check(ComponentProvider &) override;
};
