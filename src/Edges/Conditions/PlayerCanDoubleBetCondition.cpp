#include "../../../include/Edges/Conditions/PlayerCanDoubleBetCondition.hpp"

bool PlayerCanDoubleBetCondition::check(ComponentProvider &componentProvider) {
    auto & chips = dynamic_cast<ChipsComponent &>(componentProvider.getComponent("ChipsComponent"));
    return chips.getBet() <= chips.getOwned();
}