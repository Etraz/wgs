#pragma once

#include "Card.hpp"
#include "PlayingCard.hpp"

enum BridgeCallType {
    normalCall = 0, passCall = 1, doubleCall = 2, reDoubleCall = 4
};

class BridgeCall {
private:
    BridgeCallType type;
    int number;
    PlayingCardColor suite;
public:
    explicit BridgeCall(int, PlayingCardColor, BridgeCallType);

    explicit BridgeCall(std::string);

    [[nodiscard]] PlayingCardColor getSuite() const;

    [[nodiscard]] int getNumber() const;

    [[nodiscard]] BridgeCallType getType() const;
};