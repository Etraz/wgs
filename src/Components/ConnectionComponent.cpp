#include "../../include/Components/ConnectionComponent.hpp"

#include <utility>

ConnectionComponent::ConnectionComponent(const unsigned int numberOfPlayers,
                                         AbstractSendRec &connection) :
        numberOfPlayers{numberOfPlayers},
        connection{connection} {
    addresses.resize(numberOfPlayers + 1);
    sendBroadcastTo.resize(numberOfPlayers + 1, true);

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
    sendBroadcastTo.push_back(false);
}

void ConnectionComponent::restart() {
    addresses.resize(numberOfPlayers + 1);
    sendBroadcastTo.resize(numberOfPlayers + 1);
}

void ConnectionComponent::sendBroadcast(const std::string &message) {
    for (size_t i = 0; i < addresses.size(); i++)
        if (sendBroadcastTo[i])
            connection.send(message, addresses[i]);
}


