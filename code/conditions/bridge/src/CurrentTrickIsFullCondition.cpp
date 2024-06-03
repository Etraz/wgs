#include "conditions/bridge/CurrentTrickIsFullCondition.hpp"

bool CurrentTrickIsFullCondition::check(ComponentProvider &componentProvider) {
    auto &hands = dynamic_cast<HandsComponent &>(componentProvider.getComponent("HandsComponent"));
    for (int handIndex = 4; handIndex < 8; handIndex++)
        if (hands.getHand(handIndex).empty())
            return false;
    return true;
}
