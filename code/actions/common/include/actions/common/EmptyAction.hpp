#pragma once

#include "edges/Action.hpp"

class EmptyAction : public Action {
public:
    void run(ComponentProvider &) override;
};