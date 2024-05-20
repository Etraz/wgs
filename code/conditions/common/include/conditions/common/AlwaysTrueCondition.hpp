#pragma once

#include "edges/Condition.hpp"

class AlwaysTrueCondition : public Condition {
public:
    bool check(ComponentProvider &) override;
};