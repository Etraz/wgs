#pragma once
#include "Action.hpp"

class EmptyAction : public Action{
public:
    void run(ComponentProvider &) override;
};