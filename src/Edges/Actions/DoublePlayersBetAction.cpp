#include "../../../include/Edges/Actions/DoublePlayersBetAction.hpp"

void DoublePlayersBetAction::run(ComponentProvider &componentProvider) {
    auto & chips = dynamic_cast<ChipsComponent &>(componentProvider.getComponent("ChipsComponent"));
    chips.doubleBet();
}