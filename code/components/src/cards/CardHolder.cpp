#include "components/cards/CardHolder.hpp"
#include "components/cards/CardDeck.hpp"

void CardHolder::returnCard() {
    deck->returnCard(std::move(card));
}

const Card &CardHolder::getCard() const {
    return dynamic_cast<const Card &>(*card);
}

size_t CardHolder::getIndex() const {
    return index;
}

CardHolder::CardHolder(CardDeck *deck,
                       size_t index,
                       std::unique_ptr<Card> card) :
        deck{deck},
        index{index},
        card{std::move(card)} {

}