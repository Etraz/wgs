#pragma once

#include "edges/Action.hpp"

class RestartAction : public Action {
public:
    void run(ComponentProvider &) override;
};
