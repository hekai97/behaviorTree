#pragma once
#include "BehaviorTree/BTCompositesNode.h"

namespace BT
{
    class BTComposites_Selector : public BTCompositesNode
    {
    private:
        /* data */
    public:
        BTComposites_Selector(/* args */) : BTComposites_Selector("BTComposites_Selector"){};
        BTComposites_Selector(std::string name);
        ~BTComposites_Selector();
        NodeResult::BTResult ExecuteTask() override;
    };

    BTComposites_Selector::~BTComposites_Selector()
    {
    }

    BTComposites_Selector::BTComposites_Selector(std::string name)
    {
        this->bt_name = name;
    }

    inline NodeResult::BTResult BTComposites_Selector::ExecuteTask()
    {
        for (auto &child : m_children)
        {
            NodeResult::BTResult result = child->ExecuteTask();
            if (result == NodeResult::BTResult::SUCCESS)
            {
                return NodeResult::BTResult::SUCCESS;
            }
        }
        return NodeResult::BTResult::FAILURE;
    }
} // namespace BT
