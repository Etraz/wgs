#include "../../include/Components/PlayingCardsDeck.hpp"
#include <algorithm> 

void PlayingCardsDeck::createNewDeck(){
    deck.clear();
    deck.reserve(52);
    curr_index = 0;
    for (unsigned char i = 2; i < 15; ++i){
        deck.push_back(PlayingCard(i, spades));
        deck.push_back(PlayingCard(i, hearts));
        deck.push_back(PlayingCard(i, diamonds));
        deck.push_back(PlayingCard(i, clubs));
    }
    std::shuffle(deck.begin(), deck.end(), engine);
}

PlayingCardsDeck::PlayingCardsDeck(std::default_random_engine & engine): engine{engine}{
    createNewDeck();
}

PlayingCard PlayingCardsDeck::getCard(){
    if (curr_index > 63) createNewDeck();
    return deck[curr_index++];
}