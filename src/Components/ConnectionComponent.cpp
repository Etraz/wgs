#include "../../include/Components/ConnectionComponent.hpp"

ConnectionComponent::ConnectionComponent(PlayerConnection & connection): connection{connection} {}

std::string ConnectionComponent::sendMessage(std::string message) {
    return connection.getMessage(message);
}
