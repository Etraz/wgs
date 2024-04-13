#include "../../../include/Edges/Conditions/NotCondition.hpp"

#include <utility>

NotCondition::NotCondition(std::shared_ptr<Condition> condition) : condition{std::move(condition)} {}

bool NotCondition::check(ComponentProvider &componentProvider) {
    return (!condition->check(componentProvider));
}