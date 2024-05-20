#pragma once

#include "edges/Action.hpp"

class PlayerDrawsReversedCardAction : public Action {
    void run(ComponentProvider &) override;
};