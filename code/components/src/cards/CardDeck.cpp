#include "components/cards/CardDeck.hpp"
#include <algorithm>
#include <memory>

CardDeck::CardDeck(std::vector<std::unique_ptr<Card>> &&startingDeck,
                             std::default_random_engine &engine) :
        deck(std::move(startingDeck)),
        engine{engine} {
    std::shuffle(deck.begin(), deck.end(), engine);
}

void CardDeck::shuffle() {
    curr_index = 0;
    std::swap(deck, discard);
    discard.clear();
    std::shuffle(deck.begin(), deck.end(), engine);
}

std::unique_ptr<CardHolder> CardDeck::getCard() {
    if (curr_index > deck.size()) {
        shuffle();
    }
    return std::make_unique<CardHolder>(this, cardHolderIndex++, std::move(deck.at(curr_index++)));
}

void CardDeck::returnCard(std::unique_ptr<Card> &&card) {
    discard.push_back(std::move(card));
}

void CardDeck::restart() {
    cardHolderIndex = 0;
}
