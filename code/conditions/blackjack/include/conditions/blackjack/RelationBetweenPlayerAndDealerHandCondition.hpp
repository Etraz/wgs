#pragma once

#include "edges/Condition.hpp"

enum Relation {
    lesser = 0, equal = 1, greater = 2, lesserOrEqual = 4, notEqual = 8, greaterOrEqual = 16
};

class RelationBetweenPlayerAndDealerHandCondition : public Condition {
private:
    Relation relation;
public:
    explicit RelationBetweenPlayerAndDealerHandCondition(Relation);

    bool check(ComponentProvider &) override;
};