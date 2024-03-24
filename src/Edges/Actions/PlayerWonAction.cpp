#include "../../../include/Edges/Actions/PlayerWonAction.hpp"

void PlayerWonAction::run(ComponentProvider & componentProvider) {
    componentProvider.getChipsComponent().won();
}
