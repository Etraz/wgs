#include "../../include/Components/PlayingCardsDeck.hpp"
#include <algorithm>
#include <iostream>

void PlayingCardsDeck::createNewDeck() {
    deck.clear();
    deck.reserve(52);
    curr_index = 0;
    for (unsigned char i = 2; i < 15; ++i) {
        deck.emplace_back(i, spades);
        deck.emplace_back(i, hearts);
        deck.emplace_back(i, diamonds);
        deck.emplace_back(i, clubs);
    }
    std::shuffle(deck.begin(), deck.end(), engine);
}

PlayingCardsDeck::PlayingCardsDeck(std::default_random_engine &engine) : engine{engine} {
    createNewDeck();
}

PlayingCard PlayingCardsDeck::getCard() {
    if (curr_index > 51) {
        std::cout << "End of DECK " << std::endl;
        createNewDeck();
    }
    return deck[curr_index++];
}