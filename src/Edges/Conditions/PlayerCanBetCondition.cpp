#include "../../../include/Edges/Conditions/PlayerCanBetCondition.hpp"

bool PlayerCanBetCondition::check(ComponentProvider &componentProvider) {
    return (componentProvider.getChipsComponent().getOwned() > 0);
}