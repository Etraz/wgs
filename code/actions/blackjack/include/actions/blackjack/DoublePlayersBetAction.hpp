#pragma once

#include "edges/Action.hpp"

class DoublePlayersBetAction : public Action {
public:
    void run(ComponentProvider &) override;
};