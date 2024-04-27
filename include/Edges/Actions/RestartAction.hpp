#pragma once

#include "Action.hpp"

class RestartAction : public Action {
public:
    void run(ComponentProvider &) override;
};
