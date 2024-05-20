#pragma once

#include "edges/Condition.hpp"

class PlayerCanBetCondition : public Condition {
public:
    bool check(ComponentProvider &) override;
};
