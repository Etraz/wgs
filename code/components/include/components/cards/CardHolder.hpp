#pragma once

#include "Card.hpp"
#include <memory>

class CardDeck;

class CardHolder {
private:
    CardDeck *deck;
    size_t index;
    std::unique_ptr<Card> card;
public:
    CardHolder(CardDeck *, size_t, std::unique_ptr<Card>);

    void returnCard();

    [[nodiscard]] const Card &getCard() const;

    [[nodiscard]] size_t getIndex() const;

    friend void swap(CardHolder &A, CardHolder &B) {
        using std::swap;
        swap(A.deck, B.deck);
        swap(A.index, B.index);
        swap(A.card, B.card);
    }
};