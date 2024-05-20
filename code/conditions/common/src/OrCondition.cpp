#include "conditions/common/OrCondition.hpp"

#include <utility>

OrCondition::OrCondition(std::shared_ptr<Condition> first, std::shared_ptr<Condition> second) : first{std::move(first)},
                                                                                                second{std::move(
                                                                                                        second)} {}

bool OrCondition::check(ComponentProvider &componentProvider) {
    return first->check(componentProvider) or second->check(componentProvider);
}