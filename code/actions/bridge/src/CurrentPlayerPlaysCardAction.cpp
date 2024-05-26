#include "actions/bridge/CurrentPlayerPlaysCardAction.hpp"

void CurrentPlayerPlaysCardAction::run(ComponentProvider &componentProvider) {
    auto &hands = dynamic_cast<HandsComponent &>(componentProvider.getComponent("HandsComponent"));
    auto &tricks = dynamic_cast<BridgeTricksComponent &>(componentProvider.getComponent("TricksComponent"));
    auto &players = dynamic_cast<PlayerComponent &>(componentProvider.getComponent("PlayersComponent"));
    auto &connection = dynamic_cast<ConnectionComponent &>(componentProvider.getComponent("ConnectionComponent"));

    PlayerIndex currentPlayer = players.getCurrentPlayer();
    auto & hand = hands.getHand(currentPlayer);

    PlayingCardColor correctColor = dynamic_cast<const PlayingCard &>(
            hands.getHand(tricks.getTrickStartingPlayer() + 4).front()->getCard()
            ).getColor();

    std::vector<size_t> indexesToSend;
    bool hasCorrectColor = false;

    for (auto & cardHolder : hand){
        if (dynamic_cast<const PlayingCard &>(cardHolder->getCard()).getColor() == correctColor){
            hasCorrectColor = true;
            indexesToSend.push_back(cardHolder->getIndex());
        }
    }
    if (!hasCorrectColor)
        for (auto & cardHolder : hand)
            indexesToSend.push_back(cardHolder->getIndex());

    std::string message, response;
    message = "AskCardToPlay:" + std::to_string(indexesToSend.size());

    for (auto index : indexesToSend){
        message += ';';
        message += std::to_string(index);
    }
    response = connection.sendRec(message, currentPlayer);
    size_t playedIndex = std::stoi(response.substr(18));

    hands.addOpenCardToPlayer(currentPlayer + 4, hands.removeAndReturnGivenCardFromPlayer(currentPlayer, playedIndex));
}
