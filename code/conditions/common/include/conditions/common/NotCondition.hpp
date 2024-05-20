#pragma once

#include "edges/Condition.hpp"

class NotCondition : public Condition {
private:
    std::shared_ptr<Condition> condition;
public:
    explicit NotCondition(std::shared_ptr<Condition>);

    bool check(ComponentProvider &) override;
};
