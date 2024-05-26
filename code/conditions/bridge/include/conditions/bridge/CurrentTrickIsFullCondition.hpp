#pragma once

#include "edges/Condition.hpp"

class CurrentTrickIsFullCondition : public Condition{
public:
    bool check(ComponentProvider &) override;
};