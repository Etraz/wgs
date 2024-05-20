#pragma once

#include "edges/Action.hpp"

class DoubleAndReturnPlayersBetAction : public Action {
public:
    void run(ComponentProvider &) override;
};