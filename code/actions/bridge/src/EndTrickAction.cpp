#include "actions/bridge/EndTrickAction.hpp"

void EndTrickAction::run(ComponentProvider &componentProvider) {
    auto &hands = dynamic_cast<HandsComponent &>(componentProvider.getComponent("HandsComponent"));
    auto &tricks = dynamic_cast<BridgeTricksComponent &>(componentProvider.getComponent("TricksComponent"));
    auto &players = dynamic_cast<PlayerComponent &>(componentProvider.getComponent("PlayersComponent"));

    PlayerIndex startingPlayer = tricks.getTrickStartingPlayer();
    auto & startingCard = dynamic_cast<const PlayingCard &>(hands.getHand(startingPlayer + 4).front()->getCard());
    PlayerIndex winningPlayer = startingPlayer;
    PlayingCardColor trumpColor = tricks.getContractsColor();
    for (PlayerIndex playerIndex = 0; playerIndex < 4; playerIndex++){
        auto & currentCard = dynamic_cast<const PlayingCard &>(hands.getHand(playerIndex + 4).front()->getCard());
        auto & winningCard = dynamic_cast<const PlayingCard &>(hands.getHand(winningPlayer + 4).front()->getCard());
        if (currentCard.getColor() == startingCard.getColor()
                and currentCard.getColor() == winningCard.getColor()
                and currentCard.getNumber() > winningCard.getNumber())
            winningPlayer = playerIndex;
        else if (currentCard.getColor() == trumpColor
                and currentCard.getColor() != winningCard.getColor())
            winningPlayer = playerIndex;
        else if (currentCard.getColor() == trumpColor
                and currentCard.getColor() == winningCard.getColor()
                and currentCard.getNumber() > winningCard.getNumber())
            winningPlayer = playerIndex;
    }
    tricks.setTrickStartingPlayer(winningPlayer);
    while(players.getCurrentPlayer() != winningPlayer)
        players.nextPlayer();

    for(PlayerIndex playerIndex = 4; playerIndex < 8; playerIndex++)
        hands.clearPlayersHand(playerIndex);
}
