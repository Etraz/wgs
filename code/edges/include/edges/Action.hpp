#pragma once

#include "components/ComponentProvider.hpp"

class Action {
public:
    virtual void run(ComponentProvider &) = 0;

    virtual ~Action() = default;
};