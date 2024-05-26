#pragma once

#include "edges/Condition.hpp"

class HandSizeUnderXCondition : public Condition {
private:
    const size_t x;
public:
    explicit HandSizeUnderXCondition(size_t);

    bool check(ComponentProvider &) override;
};