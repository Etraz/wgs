#pragma once
#include "Action.hpp"

class PlayerDrawsCardAction : public Action{
    void run(ComponentProvider &) override;
};