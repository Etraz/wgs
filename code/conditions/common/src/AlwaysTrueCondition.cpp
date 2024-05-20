#include "conditions/common/AlwaysTrueCondition.hpp"

bool AlwaysTrueCondition::check(ComponentProvider &) {
    return true;
}