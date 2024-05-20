#include "components/cards/Card.hpp"

void Card::setShown(bool shown) {
    this->shown = shown;
}

bool Card::isShown() const {
    return this->shown;
}