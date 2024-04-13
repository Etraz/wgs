#include "../../../include/Edges/Conditions/HandSizeUnderXCondition.hpp"

HandSizeUnderXCondition::HandSizeUnderXCondition(size_t x) : x{x} {}

bool HandSizeUnderXCondition::check(ComponentProvider &componentProvider) {
    auto & hands = dynamic_cast<HandsComponent &>(componentProvider.getComponent("HandsComponent"));
    if (componentProvider.getNextPlayer() == 1)
        return hands.getPlayersHand().size() < x;
    else
        return hands.getDealersHand().size() < x;
}
