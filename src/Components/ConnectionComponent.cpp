#include "../../include/Components/ConnectionComponent.hpp"

#include <utility>

ConnectionComponent::ConnectionComponent(const unsigned int numberOfPlayers,
                                         std::unique_ptr<AbstractSendRec> &&connection,
                                         std::vector<PlayerAddress> &&orginalAddresses) :
        numberOfPlayers{numberOfPlayers},
        connection{std::move(connection)},
        addresses{std::move(orginalAddresses)} {
    addresses.resize(numberOfPlayers + 1);
    sendBroadcastTo.resize(numberOfPlayers + 1, true);
}

std::string ConnectionComponent::sendRec(std::string message, PlayerIndex index) {
    return connection->sendRec(std::move(message), addresses[index]);
}

void ConnectionComponent::send(std::string message, PlayerIndex index) {
    connection->send(std::move(message), addresses[index]);
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
            connection->send(message, addresses[i]);
}


