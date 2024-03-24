#include "../../../include/Edges/Conditions/HandSizeUnderXCondition.hpp"

HandSizeUnderXCondition::HandSizeUnderXCondition(int x): x{x} {}

bool HandSizeUnderXCondition::check(ComponentProvider & componentProvider){
    if (componentProvider.isPlayerNext())
        return componentProvider.getHandsComponent().getPlayersHand().size() < x;
    else
        return componentProvider.getHandsComponent().getDealersHand().size() < x;
}
