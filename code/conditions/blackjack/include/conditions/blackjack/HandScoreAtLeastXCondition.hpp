#pragma once

#include "edges/Condition.hpp"

class HandScoreAtLeastXCondition : public Condition {
private:
    const int x;
public:
    HandScoreAtLeastXCondition(int);

    bool check(ComponentProvider &) override;
};