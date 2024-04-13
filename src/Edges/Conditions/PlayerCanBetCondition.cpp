#include "../../../include/Edges/Conditions/PlayerCanBetCondition.hpp"

bool PlayerCanBetCondition::check(ComponentProvider &componentProvider) {
    Component & comp = componentProvider.getComponent("ChipsComponent");
    auto & chips = dynamic_cast<ChipsComponent &>(comp);
    return (chips.getOwned() > 0);
}