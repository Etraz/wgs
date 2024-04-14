#include "../../include/Components/ConnectionComponent.hpp"

ConnectionComponent::ConnectionComponent(AbstractSendRec &connection) : connection{connection} {}

std::string ConnectionComponent::sendMessage(std::string message) {
    return connection.getMessage(message);
}
