#pragma once

#include "Condition.hpp"

class HandSizeUnderXCondition : public Condition {
private:
    const int x;
public:
    HandSizeUnderXCondition(int);

    bool check(ComponentProvider &) override;
};