#include "../../../include/Edges/Conditions/PlayerCanSplitCondition.hpp"

bool PlayerCanSplitCondition::check(ComponentProvider & componentProvider) {
    auto & hands = dynamic_cast<HandsComponent &>(componentProvider.getComponent("HandsComponent"));
    auto & players = dynamic_cast<PlayerComponent &>(componentProvider.getComponent("PlayersComponent"));
    auto & chips = dynamic_cast<ChipsComponent &>(componentProvider.getComponent("ChipsComponent"));
    auto & hand = hands.getHand(players.getCurrentPlayer());

    if (hand.size() != 2)
        return false;

    auto & card0 = dynamic_cast<const PlayingCard &>(hand[0]->getCard());
    auto & card1 = dynamic_cast<const PlayingCard &>(hand[1]->getCard());
    return (card0.getNumber() == card1.getNumber()) and (chips.getBet(players.getCurrentPlayer()) <= chips.getOwned(players.getCurrentPlayer()));
}