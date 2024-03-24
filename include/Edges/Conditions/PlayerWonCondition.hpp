#pragma once
#include "Condition.hpp"

class PlayerWonCondition : public Condition{
    bool check(ComponentProvider &) override;
};