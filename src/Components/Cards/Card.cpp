#include "../../../include/Components/Cards/Card.hpp"

void Card::setShown(bool shown) {
    this->shown = shown;
}

bool Card::isShown() const {
    return this->shown;
}