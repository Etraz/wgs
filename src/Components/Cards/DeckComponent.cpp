#include "../../../include/Components/Cards/DeckComponent.hpp"
#include <algorithm>
#include <memory>

DeckComponent::DeckComponent(std::vector<std::unique_ptr<Card>> && startingDeck,
                             std::default_random_engine & engine):
                             deck(std::move(startingDeck)),
                             engine{engine} {
    std::shuffle(deck.begin(), deck.end(), engine);
}

void DeckComponent::shuffle() {
    curr_index = 0;
    std::swap(deck, discard);
    discard.clear();
    std::shuffle(deck.begin(), deck.end(), engine);
}

std::unique_ptr<CardHolder> DeckComponent::getCard() {
    if (curr_index > deck.size()) {
        shuffle();
    }
    return std::make_unique<CardHolder>(this, cardHolderIndex, std::move(deck.at(curr_index++)));
}

void DeckComponent::returnCard(std::unique_ptr<Card> && card) {
    discard.push_back(std::move(card));
}
