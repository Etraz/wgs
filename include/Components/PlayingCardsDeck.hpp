#pragma once
#include "PlayingCard.hpp"
#include <random>

class PlayingCardsDeck{
private:
    std::vector<PlayingCard> deck;
    std::default_random_engine engine;
    int curr_index{};
    void createNewDeck();
public:
    explicit PlayingCardsDeck(std::default_random_engine&);
    PlayingCard getCard();
};