#include "../../../include/Edges/Actions/ClearHandsAction.hpp"

void ClearHandsAction::run(ComponentProvider &componentProvider) {
    auto & hands = dynamic_cast<HandsComponent &>(componentProvider.getComponent("HandsComponent"));
    hands.clear();
}
