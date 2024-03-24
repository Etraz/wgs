#include "../../../include/Edges/Conditions/PlayerCanDoubleBetCondition.hpp"

bool PlayerCanDoubleBetCondition::check(ComponentProvider & componentProvider){
    return componentProvider.getChipsComponent().getBet() <= componentProvider.getChipsComponent().getOwned();
}