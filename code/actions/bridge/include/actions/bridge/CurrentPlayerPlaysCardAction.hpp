#pragma once

#include "edges/Action.hpp"

class CurrentPlayerPlaysCardAction : public Action{
public:
    void run(ComponentProvider &) override;
};