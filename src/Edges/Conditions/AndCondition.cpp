#include "../../../include/Edges/Conditions/AndCondition.hpp"

#include <utility>

AndCondition::AndCondition(std::shared_ptr<Condition> first, std::shared_ptr<Condition> second) : first{std::move(first)}, second{std::move(second)} {}

bool AndCondition::check(ComponentProvider &componentProvider) {
    return first->check(componentProvider) and second->check(componentProvider);
}