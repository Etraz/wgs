#pragma once

#include "edges/Action.hpp"

class EndTrickAction : public Action {
public:
    void run(ComponentProvider &) override;
};
