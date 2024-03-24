#pragma once
#include "Condition.hpp"

class NotCondition : public Condition {
private:
    Condition & condition;
public:
    NotCondition(Condition &);
    bool check(ComponentProvider &) override;
};
