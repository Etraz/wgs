#pragma once

#include "edges/Action.hpp"

class BridgeRestartAction : public Action {
public:
    void run(ComponentProvider &) override;
};