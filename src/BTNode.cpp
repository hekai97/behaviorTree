#include "BehaviorTree/BTNode.h"

namespace BT
{

    BTNode::BTNode(/* args */) : BTNode("BTNode")
    {
    }
    BTNode::BTNode(std::string name)
    {
        bt_name = name;
    }

    BTNode::~BTNode()
    {
    }

    inline void BTNode::setName(std::string name)
    {
        bt_name = name;
    }

    inline std::string BTNode::getName() const
    {
        return bt_name;
    }
    
} // namespace BT
