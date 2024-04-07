#include "../../../include/Edges/Actions/ChangeToPlayerAction.hpp"

void ChangeToPlayerAction::run(ComponentProvider &componentProvider) {
    componentProvider.setNextPlayer(1);
}