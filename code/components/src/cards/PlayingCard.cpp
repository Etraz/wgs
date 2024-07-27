#include "components/cards/PlayingCard.hpp"


PlayingCard::PlayingCard(int number, PlayingCardColor color) : number{number}, color{color} {}


int PlayingCard::getNumber() const {
    return this->number;
}

PlayingCardColor PlayingCard::getColor() const {
    return this->color;
}


std::string PlayingCard::serialize() const {
    std::string toReturn = "playingCard_";
    toReturn += ToString(color);
    toReturn += '_';
    switch (number) {
        case 11:
            toReturn += "jack";
            break;
        case 12:
            toReturn += "queen";
            break;
        case 13:
            toReturn += "king";
            break;
        case 14:
            toReturn += "ace";
            break;
        default:
            toReturn += std::to_string(number);
    }
    return toReturn;
}

std::string toString(const PlayingCard &card) {
    std::string toReturn = "| ";
    switch (card.getNumber()) {
        case 11:
            toReturn += "Jack";
            break;
        case 12:
            toReturn += "Queen";
            break;
        case 13:
            toReturn += "King";
            break;
        case 14:
            toReturn += "Ace";
            break;
        default:
            toReturn += std::to_string(card.getNumber());
    }
    toReturn += " of ";
    toReturn += ToString(card.getColor());
    toReturn += " |";
    return toReturn;
}

std::string PlayingCard::serializeReverse() const {
    return "playing_card/reversed";
}

std::string toString(const std::vector<std::unique_ptr<CardHolder>> &hand) {
    std::string message;
    for (const auto &cardHolder: hand) {
        auto &card = dynamic_cast<const PlayingCard &>(cardHolder->getCard());
        message += toString(card);
        message += ' ';
    }
    return message;
}

std::ostream &operator<<(std::ostream &os, const PlayingCard &card) {
    os << toString(card);
    return os;
}