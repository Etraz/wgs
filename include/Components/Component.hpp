#pragma once

#include <string>

using PlayerIndex = unsigned int;

std::string to_string(PlayerIndex playerIndex);

class Component{
public:
    virtual ~Component() = default;
};