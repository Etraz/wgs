#pragma once

#include "Action.hpp"

class SendMessageAction : public Action {
private:
    std::string message;
public:
    SendMessageAction(std::string);

    void run(ComponentProvider &) override;
};
