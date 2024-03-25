#pragma once

#include "Action.hpp"

class PlayerDrawsReversedCardAction : public Action {
    void run(ComponentProvider &) override;
};