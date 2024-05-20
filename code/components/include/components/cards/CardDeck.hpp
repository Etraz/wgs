#pragma once

#include "CardHolder.hpp"
#include "PlayingCard.hpp"
#include "components/Component.hpp"
#include <random>
#include <memory>

class CardDeck : public Component {
private:
    std::vector<std::unique_ptr<Card>> deck;
    std::vector<std::unique_ptr<Card>> discard{};
    std::default_random_engine engine;
    size_t curr_index{}, cardHolderIndex{};

    void shuffle();


public:
    CardDeck(std::vector<std::unique_ptr<Card>> &&, std::default_random_engine &);

    void returnCard(std::unique_ptr<Card> &&);

    std::unique_ptr<CardHolder> getCard();

    void restart();
};