#pragma once

#include "../../Components/ComponentProvider.hpp"

class Condition {
public:
    virtual bool check(ComponentProvider &) = 0;

    virtual ~Condition() = default;
};