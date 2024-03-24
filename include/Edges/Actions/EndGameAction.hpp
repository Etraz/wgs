#pragma once
#include "Action.hpp"

class EndGameAction : public Action {
    void run(ComponentProvider &) override;
};