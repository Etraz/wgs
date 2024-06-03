#pragma once

#include "edges/Action.hpp"

class EndGameAction : public Action {
    void run(ComponentProvider &) override;
};