#pragma once

#include "edges/Action.hpp"

class CurrentPlayerStartsNewTrickAction : public Action {
public:
    void run(ComponentProvider &) override;
};
