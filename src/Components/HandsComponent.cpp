#include "../../include/Components/HandsComponent.hpp"
#include "../../include/Components/ComponentProvider.hpp"

void HandsComponent::clear() {
    for (auto & cardHolder : players)
        cardHolder->returnCard();
    for (auto & cardHolder : dealers)
        cardHolder->returnCard();
    players.clear();
    dealers.clear();
    getConnectionComponent().sendMessage("{player:0,\naction:clear}");
    getConnectionComponent().sendMessage("{player:1,\naction:clear}");
}

const std::vector<std::unique_ptr<CardHolder>> &HandsComponent::getPlayersHand() const{
    return players;
}

const std::vector<std::unique_ptr<CardHolder>> &HandsComponent::getDealersHand() const{
    return dealers;
}

void HandsComponent::addCardToPlayer(PlayerIndex playerIndex, std::unique_ptr<CardHolder> cardHolder) {
    //TODO multiplayer solution
    std::string message = "{player:";
    message += to_string(playerIndex);
    message += ",\naction:draw,\ncard:{card_index:";
    message += std::to_string(cardHolder->getIndex());
    message += ",card_value:";
    message += cardHolder->getCard().serialize();
    message += "}}";
    getConnectionComponent().sendMessage(message);
    if (playerIndex == 1)
        players.push_back(std::move(cardHolder));
    else
        dealers.push_back(std::move(cardHolder));
}

void HandsComponent::showPlayersCards(PlayerIndex playerIndex) {
    auto & hand = playerIndex == 1 ? players : dealers;
    for (auto & cardHolder: hand){
        auto & card = dynamic_cast<const PlayingCard &>(cardHolder->getCard());
        if (!card.isShown()) {
            cardHolder->reverseCard();
            std::string message = "{player:";
            message += to_string(playerIndex);
            message += ",\naction:show,\ncard:{card_index:";
            message += std::to_string(cardHolder->getIndex());
            message += ",card_value:";
            message += cardHolder->getCard().serialize();
            message += "}}";
            getConnectionComponent().sendMessage(message);
        }
    }
}

HandsComponent::HandsComponent(ComponentProvider & componentProvider) : componentProvider{componentProvider}{

}

ConnectionComponent &HandsComponent::getConnectionComponent() {
    return dynamic_cast<ConnectionComponent &>(componentProvider.getComponent("ConnectionComponent"));
}
