#pragma once

#include "Cards/DeckComponent.hpp"
#include "ChipsComponent.hpp"
#include "ConnectionComponent.hpp"
#include "HandsComponent.hpp"
#include "PlayerComponent.hpp"
#include <map>

class ComponentProvider {
private:
    std::map<std::string, std::unique_ptr<Component>> Components;
    bool gameToContinue{true};
public:
    ComponentProvider() = default;

    void addComponent(std::unique_ptr<Component>, const std::string&);
    [[nodiscard]] Component & getComponent(const std::string&) const;

    void setGameToContinue(bool);
    [[nodiscard]] bool isGameToContinue() const;
};