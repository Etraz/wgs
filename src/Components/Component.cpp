#include "../../include/Components/Component.hpp"
#include "../../include/Components/ComponentProvider.hpp"

std::string to_string(PlayerIndex playerIndex){
    return std::to_string(static_cast<unsigned int>(playerIndex));
}
