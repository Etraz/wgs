#include "../../../include/Edges/Actions/ClearHandsAction.hpp"

void ClearHandsAction::run(ComponentProvider & componentProvider) {
    componentProvider.getHandsComponent().clear();
}
