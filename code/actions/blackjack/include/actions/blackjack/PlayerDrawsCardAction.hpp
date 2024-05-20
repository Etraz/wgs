#pragma once

#include "edges/Action.hpp"

class PlayerDrawsCardAction : public Action {
    void run(ComponentProvider &) override;
};