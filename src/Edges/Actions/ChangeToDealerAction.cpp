#include "../../../include/Edges/Actions/ChangeToDealerAction.hpp"

void ChangeToDealerAction::run(ComponentProvider &componentProvider) {
    componentProvider.setPlayerNext(false);
}