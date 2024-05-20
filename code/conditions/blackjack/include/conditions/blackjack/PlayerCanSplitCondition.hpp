#pragma once

#include "edges/Condition.hpp"

class PlayerCanSplitCondition : public Condition {
    bool check(ComponentProvider &) override;
};