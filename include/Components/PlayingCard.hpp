#pragma once

#include <ostream>
#include <vector>

enum PlayingCardColor {
    spades = 1, hearts = 2, diamonds = 4, clubs = 8
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
        default:
            return "[Unknown color]";
    }
}

class PlayingCard {
private:
    bool shown{true};
    int number{2};
    PlayingCardColor color;
public:
    PlayingCard(int, PlayingCardColor);

    int getNumber() const;

    PlayingCardColor getColor() const;

    void setShown(bool);

    bool isShown() const;


    friend void swap(PlayingCard &A, PlayingCard &B) {
        using std::swap;
        swap(A.color, B.color);
        swap(A.number, B.number);
        swap(A.shown, B.shown);
    }
};

std::string toString(const PlayingCard &card);

std::string toString(const std::vector<PlayingCard> &hand);

std::ostream &operator<<(std::ostream &os, const PlayingCard &card);