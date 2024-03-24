#include "../include/Game.hpp"

Game::Game(ComponentProvider & componentProvider,
           Graph & graph):
           componentProvider{componentProvider},
           graph{graph} {}

void Game::start(){
    while(componentProvider.isGameToContinue())
        graph.move();
}