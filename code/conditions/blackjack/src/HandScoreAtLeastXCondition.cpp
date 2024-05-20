#include "conditions/blackjack/HandScoreAtLeastXCondition.hpp"

HandScoreAtLeastXCondition::HandScoreAtLeastXCondition(int x) : x{x} {}

bool HandScoreAtLeastXCondition::check(ComponentProvider &componentProvider) {
    auto &hands = dynamic_cast<HandsComponent &>(componentProvider.getComponent("HandsComponent"));
    auto &players = dynamic_cast<PlayerComponent &>(componentProvider.getComponent("PlayersComponent"));
    auto &hand = hands.getHand(players.getCurrentPlayer());
    int sum{}, numberOfAces{}, number;
    for (auto &cardHolder: hand) {
        auto &card = dynamic_cast<const PlayingCard &>(cardHolder->getCard());
        number = card.getNumber();
        if (number < 11)
            sum += number;
        else if (number < 14)
            sum += 10;
        else {
            sum += 11;
            numberOfAces += 1;
        }
        if (sum > 21 and numberOfAces > 0) {
            numberOfAces -= 1;
            sum -= 10;
        }
    }
    return sum >= x;
}