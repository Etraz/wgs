#pragma once

#include "edges/Condition.hpp"

class AndCondition : public Condition {
private:
    std::shared_ptr<Condition> first, second;
public:
    AndCondition(std::shared_ptr<Condition>, std::shared_ptr<Condition>);

    bool check(ComponentProvider &) override;
};