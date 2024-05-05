#include "../../include/Components/ConnectionComponent.hpp"

#include <utility>

ConnectionComponent::ConnectionComponent(const unsigned int numberOfPlayers,
                                         AbstractSendRec &connection) :
        numberOfPlayers{numberOfPlayers},
        connection{connection} {
    addresses.resize(numberOfPlayers + 1);

    // to be removed
    for (size_t i = 0; i <= numberOfPlayers; i++)
        addresses[i] = i;
}

std::string ConnectionComponent::sendRec(std::string message, PlayerIndex index) {
    return connection.sendRec(std::move(message), addresses[index]);
}

void ConnectionComponent::send(std::string message, PlayerIndex index) {
    connection.send(std::move(message), addresses[index]);
}

void ConnectionComponent::splitConnection(PlayerIndex index) {
    addresses.push_back(addresses[index]);
}

void ConnectionComponent::restart() {
    addresses.resize(numberOfPlayers + 1);
}

void ConnectionComponent::sendBroadcast(const std::string &messege) {
    for (size_t i = 1; i < addresses.size(); i++)
        connection.send(messege, addresses[i]);
}


