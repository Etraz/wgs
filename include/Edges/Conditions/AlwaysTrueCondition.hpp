#pragma once

#include "Condition.hpp"

class AlwaysTrueCondition : public Condition {
public:
    bool check(ComponentProvider &) override;
};