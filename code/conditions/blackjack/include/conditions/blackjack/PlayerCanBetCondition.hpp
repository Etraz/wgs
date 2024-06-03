#pragma once

#include "edges/Condition.hpp"

class [[maybe_unused]] PlayerCanBetCondition : public Condition {
public:
    bool check(ComponentProvider &) override;
};
