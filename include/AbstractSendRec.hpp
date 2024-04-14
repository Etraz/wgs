#pragma once

#include <string>

class AbstractSendRec{
public:
    virtual std::string getMessage(std::string) = 0;
};