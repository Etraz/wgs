#include "../../../include/Edges/Conditions/AndCondition.hpp"

AndCondition::AndCondition(Condition & first, Condition & second): first{first}, second{second} {}

bool AndCondition::check(ComponentProvider & componentProvider) {
    return first.check(componentProvider) and second.check(componentProvider);
}