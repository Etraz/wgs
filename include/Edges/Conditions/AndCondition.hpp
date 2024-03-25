#pragma once

#include "Condition.hpp"

class AndCondition : public Condition {
private:
    Condition &first, &second;
public:
    AndCondition(Condition &, Condition &);

    bool check(ComponentProvider &) override;
};