#pragma once

#include "edges/action.hpp"

class EndTrickAction : public Action{
public:
    void run(ComponentProvider &) override;
};
