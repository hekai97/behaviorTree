#include "BehaviorTree.h"
#include "BehaviorTreeType.h"
class IBehavior
{
public:
    virtual ~IBehavior() {}
    virtual void OnInitialize() = 0;
};