#pragma once
#include "Card.hpp"
#include <memory>

class DeckComponent;

class CardHolder {
private:
    DeckComponent * deck;
    size_t index;
    std::unique_ptr<Card> card;
public:
    CardHolder(DeckComponent *, size_t, std::unique_ptr<Card>);
    void returnCard();
    const Card & getCard() const;
    size_t getIndex() const;
    friend void swap(CardHolder &A, CardHolder &B) {
        using std::swap;
        swap(A.deck, B.deck);
        swap(A.index, B.index);
        swap(A.card, B.card);
    }
    void reverseCard();
};