#include <memory>
#include "BehaviorTree.h"
#include "BehaviorTreeType.h"
class IBehavior
{
public:
    virtual ~IBehavior() {}
    virtual void OnInitialize() = 0;
protected:
    std::shared_ptr<BT::BehaviorTree> m_tree; 
};
