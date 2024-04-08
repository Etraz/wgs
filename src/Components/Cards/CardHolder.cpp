#include "../../../include/Components/Cards/CardHolder.hpp"
#include "../../../include/Components/Cards/DeckComponent.hpp"

void CardHolder::returnCard(){
    deck->returnCard(std::move(card));
}

const Card & CardHolder::getCard() const{
    return dynamic_cast<const Card &>(*card);
}

size_t CardHolder::getIndex() const{
    return index;
}

CardHolder::CardHolder(DeckComponent * deck,
                       size_t index,
                       std::unique_ptr<Card> card):
                        deck{deck},
                        index{index},
                        card{std::move(card)} {

}

void CardHolder::reverseCard() {
    card->setShown(!card->isShown());
}


