#pragma once
#include "BehaviorTreeType.h"

namespace BT
{

    class BTNode
    {
    private:
        /* data */
    public:
        BTNode(/* args */);
        ~BTNode();
        virtual BTNodeType getType() const = 0;
        virtual NodeResult::BTResult ExecuteTask() = 0;
    };

    BTNode::BTNode(/* args */)
    {
    }

    BTNode::~BTNode()
    {
    }

} // namespace BT
