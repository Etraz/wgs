#include "../../../include/Edges/Actions/ChangeToDealerAction.hpp"

void ChangeToDealerAction::run(ComponentProvider &componentProvider) {
    componentProvider.setNextPlayer(0);
}