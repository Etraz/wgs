#pragma once

#include "Action.hpp"

class ChangeToDealerAction : public Action {
    void run(ComponentProvider &) override;
};
