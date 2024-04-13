#include "../../include/Components/Component.hpp"

std::string to_string(PlayerIndex playerIndex){
    return std::to_string(static_cast<unsigned int>(playerIndex));
}