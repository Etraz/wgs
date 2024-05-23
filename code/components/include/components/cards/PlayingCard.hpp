#pragma once

#include <ostream>
#include <vector>
#include "Card.hpp"
#include "CardHolder.hpp"

enum PlayingCardColor {
    clubs = 0,  diamonds = 1, hearts = 2, spades = 4, noTrump = 8
};

inline const char *ToString(PlayingCardColor c) {
    switch (c) {
        case spades:
            return "spades";
        case hearts:
            return "hearts";
        case diamonds:
            return "diamonds";
        case clubs:
            return "clubs";
        case noTrump:
            return "noTrump";
        default:
            return "[Unknown color]";
    }
}

class PlayingCard : public Card {
private:
    int number{2};
    PlayingCardColor color;
public:
    PlayingCard(int, PlayingCardColor);

    [[nodiscard]] int getNumber() const;

    [[nodiscard]] PlayingCardColor getColor() const;


    [[nodiscard]] std::string serialize() const override;
    [[nodiscard]] std::string serializeReverse() const override;


    friend void swap(PlayingCard &A, PlayingCard &B) {
        using std::swap;
        swap(A.color, B.color);
        swap(A.number, B.number);
    }
};

std::string toString(const PlayingCard &card);

std::string toString(const std::vector<std::unique_ptr<CardHolder>> &hand);

std::ostream &operator<<(std::ostream &os, const PlayingCard &card);