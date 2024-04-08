#include "../../../include/Edges/Conditions/HandSizeUnderXCondition.hpp"

HandSizeUnderXCondition::HandSizeUnderXCondition(int x) : x{x} {}

bool HandSizeUnderXCondition::check(ComponentProvider &componentProvider) {
    if (componentProvider.getNextPlayer() == 1)
        return componentProvider.getHandsComponent().getPlayersHand().size() < x;
    else
        return componentProvider.getHandsComponent().getDealersHand().size() < x;
}
