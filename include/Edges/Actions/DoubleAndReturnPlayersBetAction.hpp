#pragma once

#include "Action.hpp"

class DoubleAndReturnPlayersBetAction : public Action {
public:
    void run(ComponentProvider &) override;
};