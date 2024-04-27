#pragma once

#include "Condition.hpp"

class PlayerCanSplitCondition : public Condition {
    bool check(ComponentProvider &) override;
};