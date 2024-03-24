#include "../../../include/Edges/Conditions/BlackjackAtLeastXCondition.hpp"
#include "vector"

BlackjackAtLeastXCondition::BlackjackAtLeastXCondition(int x): x{x} {}

bool BlackjackAtLeastXCondition::check(ComponentProvider & componentProvider) {
    std::vector<PlayingCard> hand;
    int sum{}, numberOfAces{}, number;
    if (componentProvider.isPlayerNext())
        hand = componentProvider.getHandsComponent().getPlayersHand();
    else
        hand = componentProvider.getHandsComponent().getDealersHand();
    for (auto card : hand){
        number = card.getNumber();
        if (number < 11)
            sum += number;
        else if (number < 14)
            sum += 10;
        else {
            sum += 11;
            numberOfAces += 1;
        }
        if (sum > 21 and numberOfAces > 0){
            numberOfAces -= 1;
            sum -= 10;
        }
    }
    return sum >= x;
}