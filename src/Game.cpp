#include "../include/Game.hpp"

#include <utility>

Game::Game(std::shared_ptr<ComponentProvider> componentProvider,
           std::unique_ptr<Graph> &&graph) :
        componentProvider{std::move(componentProvider)},
        graph{std::move(graph)} {}

void Game::start() {
    while (componentProvider->isGameToContinue())
        graph->move();
}