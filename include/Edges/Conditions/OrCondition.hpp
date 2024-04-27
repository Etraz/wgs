#pragma once

#include "Condition.hpp"

class OrCondition : public Condition {
private:
    std::shared_ptr<Condition> first, second;
public:
    OrCondition(std::shared_ptr<Condition>, std::shared_ptr<Condition>);

    bool check(ComponentProvider &) override;
};