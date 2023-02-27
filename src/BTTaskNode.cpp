#include "BehaviorTree/BTTaskNode.h"

namespace BT{

    BTTaskNode::BTTaskNode(/* args */) : BTTaskNode("BTTaskNode")
    {
    }
    BTTaskNode::BTTaskNode(std::string name)
    {
        this->bt_name = name;
    }

    BTTaskNode::~BTTaskNode()
    {
    }

    inline NodeResult::BTResult BTTaskNode::ExecuteTask()
    {
        return NodeResult::BTResult::SUCCESS;
    }

    inline BTNodeType BTTaskNode::getType() const
    {
        return BTNodeType::ACTION;
    }
}