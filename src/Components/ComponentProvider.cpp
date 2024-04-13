#include "../../include/Components/ComponentProvider.hpp"

void ComponentProvider::setNextPlayer(PlayerIndex playerIndex) {
    this->nextPlayerIndex = playerIndex;
}

PlayerIndex ComponentProvider::getNextPlayer() const {
    return nextPlayerIndex;
}

bool ComponentProvider::isGameToContinue() const {
    return gameToContinue;
}

void ComponentProvider::setGameToContinue(bool gameToContinue) {
    this->gameToContinue = gameToContinue;
}

void ComponentProvider::addComponent(std::unique_ptr<Component> component, const std::string& name) {
    Components.insert(std::make_pair(name, std::move(component)));
}

Component &ComponentProvider::getComponent(const std::string& name) const {
    if (auto iter = Components.find(name); iter != Components.end())
        return *(iter->second);
    throw std::runtime_error("No component found");
}
