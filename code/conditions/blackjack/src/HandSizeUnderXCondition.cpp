#include "conditions/blackjack/HandSizeUnderXCondition.hpp"

HandSizeUnderXCondition::HandSizeUnderXCondition(size_t x) : x{x} {}

bool HandSizeUnderXCondition::check(ComponentProvider &componentProvider) {
    auto &hands = dynamic_cast<HandsComponent &>(componentProvider.getComponent("HandsComponent"));
    auto &players = dynamic_cast<PlayerComponent &>(componentProvider.getComponent("PlayersComponent"));
    auto &hand = hands.getHand(players.getCurrentPlayer());

    return hand.size() < x;
}