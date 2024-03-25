#pragma once

#include "PlayingCard.hpp"
#include <vector>

class HandsComponent {
private:
    std::vector<PlayingCard> players, dealers;
public:
    std::vector<PlayingCard> &getPlayersHand();

    std::vector<PlayingCard> &getDealersHand();

    void clear();
};