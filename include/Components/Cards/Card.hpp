#pragma once

#include <string>

class Card {
protected:
    bool shown{true};
public:
    [[nodiscard]] virtual std::string serialize() const = 0;

    virtual ~Card() = default;

    void setShown(bool);

    [[nodiscard]] bool isShown() const;
};