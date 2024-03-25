#include "Condition.hpp"

class BlackjackAtLeastXCondition : public Condition {
private:
    const int x;
public:
    BlackjackAtLeastXCondition(int);

    bool check(ComponentProvider &) override;
};