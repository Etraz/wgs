#include "../../../include/Edges/Conditions/RelationBetweenPlayerAndDealerHandCondition.hpp"

RelationBetweenPlayerAndDealerHandCondition::RelationBetweenPlayerAndDealerHandCondition(Relation relation) : relation{
        relation} {}

bool RelationBetweenPlayerAndDealerHandCondition::check(ComponentProvider &componentProvider) {
    auto & hands = dynamic_cast<HandsComponent &>(componentProvider.getComponent("HandsComponent"));
    int sumPlayer{}, sumDealer{}, numberOfAces{}, number;
    auto & playerHand = hands.getPlayersHand();
    auto & dealerHand = hands.getDealersHand();
    for (auto & cardHolder: playerHand){
        auto & card = dynamic_cast<const PlayingCard &>(cardHolder->getCard());
        number = card.getNumber();
        if (number < 11)
            sumPlayer += number;
        else if (number < 14)
            sumPlayer += 10;
        else {
            sumPlayer += 11;
            numberOfAces += 1;
        }
        if (sumPlayer > 21 and numberOfAces > 0) {
            numberOfAces -= 1;
            sumPlayer -= 10;
        }
    }
    numberOfAces = 0;
    for (auto & cardHolder: dealerHand){
        auto & card = dynamic_cast<const PlayingCard &>(cardHolder->getCard());
        number = card.getNumber();
        if (number < 11)
            sumDealer += number;
        else if (number < 14)
            sumDealer += 10;
        else {
            sumDealer += 11;
            numberOfAces += 1;
        }
        if (sumDealer > 21 and numberOfAces > 0) {
            numberOfAces -= 1;
            sumDealer -= 10;
        }
    }
    switch (relation) {
        case lesser:
            return sumPlayer < sumDealer;
        case equal:
            return sumPlayer == sumDealer;
        case greater:
            return sumPlayer > sumDealer;
        case lesserOrEqual:
            return sumPlayer <= sumDealer;
        case notEqual:
            return sumPlayer != sumDealer;
        case greaterOrEqual:
            return sumPlayer >= sumDealer;
        default:
            throw std::runtime_error("Bad enum type");
    }
}