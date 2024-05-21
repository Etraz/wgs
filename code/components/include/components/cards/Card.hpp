#pragma once

#include <string>

class Card {

public:
    [[nodiscard]] virtual std::string serialize() const = 0;
    virtual  std::string serializeReverse() const = 0;

    virtual ~Card() = default;

};