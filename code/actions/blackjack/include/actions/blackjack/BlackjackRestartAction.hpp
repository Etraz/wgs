#pragma once

#include "edges/Action.hpp"

class BlackjackRestartAction : public Action {
public:
    void run(ComponentProvider &) override;
};
