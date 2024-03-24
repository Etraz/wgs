#include "../../../include/Edges/Actions/DoublePlayersBetAction.hpp"

void DoublePlayersBetAction::run(ComponentProvider & componentProvider) {
    componentProvider.getChipsComponent().doubleBet();
}