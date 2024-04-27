#include "../../include/Components/ComponentProvider.hpp"

bool ComponentProvider::isGameToContinue() const {
    return gameToContinue;
}

void ComponentProvider::setGameToContinue(bool toContinue) {
    gameToContinue = toContinue;
}


void ComponentProvider::addComponent(std::unique_ptr<Component> component, const std::string &name) {
    Components.insert(std::make_pair(name, std::move(component)));
}

Component &ComponentProvider::getComponent(const std::string &name) const {
    if (auto iter = Components.find(name); iter != Components.end())
        return *(iter->second);
    throw std::runtime_error("No component found");
}