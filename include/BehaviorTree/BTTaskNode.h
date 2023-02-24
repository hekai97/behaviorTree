#pragma once
#include "BTNode.h"
namespace BT
{
    class BTTaskNode : public BTNode
    {
    private:
        /* data */
    public:
        BTTaskNode(/* args */) : BTTaskNode("BTTaskNode"){};
        BTTaskNode(std::string name);
        ~BTTaskNode();
        NodeResult::BTResult ExecuteTask() override;
        BTNodeType getType() const override final;
    };

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

} // namespace BT
