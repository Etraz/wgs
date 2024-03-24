#pragma once
#include "Action.hpp"

class PlayerWonAction : public Action{
public:
    void run(ComponentProvider &) override;
};