#pragma once

#include "Action.hpp"

class DoublePlayersBetAction : public Action {
public:
    void run(ComponentProvider &) override;
};