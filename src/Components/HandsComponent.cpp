#include "../../include/Components/HandsComponent.hpp"

std::vector<PlayingCard> & HandsComponent::getPlayersHand(){
    return players;
}

std::vector<PlayingCard> & HandsComponent::getDealersHand(){
    return dealers;
}

void HandsComponent::clear() {
    players.clear();
    dealers.clear();
}
