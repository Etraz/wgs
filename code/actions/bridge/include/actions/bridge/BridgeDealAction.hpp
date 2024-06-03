#pragma once

#include "edges/Action.hpp"

class BridgeDealAction : public Action {
public:
    void run(ComponentProvider &) override;
};