#include "../../../include/Edges/Conditions/PlayerWonCondition.hpp"

bool PlayerWonCondition::check(ComponentProvider &componentProvider) {
    std::vector<PlayingCard> playerHand, dealerHand;
    int sumPlayer{}, sumDealer{}, numberOfAces{}, number;
    playerHand = componentProvider.getHandsComponent().getPlayersHand();
    dealerHand = componentProvider.getHandsComponent().getDealersHand();
    for (auto card: playerHand) {
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
    for (auto card: dealerHand) {
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
    return sumDealer > 21 or sumPlayer > sumDealer;
}