#include "../../include/Components/PlayingCard.hpp"



PlayingCard::PlayingCard(int number, PlayingCardColor color): number{number}, color{color} {}


int PlayingCard::getNumber() const{
    return this-> number;
}

PlayingCardColor PlayingCard::getColor() const{
    return this -> color;
}

void PlayingCard::setShown(bool shown){
    this->shown = shown;
}

bool PlayingCard::isShown() const{
    return this->shown;
}

std::string toString(const PlayingCard & card){
    std::string toReturn;
    if (!card.isShown())
        return "Reversed Card";
    switch (card.getNumber()){
        case 11:
            toReturn = "Jack";
            break;
        case 12:
            toReturn = "Queen";
            break;
        case 13:
            toReturn = "King";
            break;
        case 14:
            toReturn = "Ace";
            break;
        default:
            toReturn = std::to_string(card.getNumber());
    }
    toReturn += " of ";
    toReturn += ToString(card.getColor());
    return toReturn;
}

std::string toString(const std::vector<PlayingCard> & hand){
    std::string message = "";
    for (const auto & card: hand){
        message += toString(card);
        message += ' ';
    }
    return message;
}

std::ostream & operator<<(std::ostream & os, const PlayingCard & card){
    os << toString(card);
    return os;
}