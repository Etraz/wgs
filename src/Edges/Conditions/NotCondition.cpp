#include "../../../include/Edges/Conditions/NotCondition.hpp"

NotCondition::NotCondition(Condition & condition): condition{condition} {}

bool NotCondition::check(ComponentProvider & componentProvider){
    return (!condition.check(componentProvider));
}