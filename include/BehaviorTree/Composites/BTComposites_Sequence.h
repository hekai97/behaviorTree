#pragma once
#include "BehaviorTree/BTCompositesNode.h"
namespace BT
{
    class BTComposites_Sequence : public BTCompositesNode
    {
    private:
        /* data */
    public:
        BTComposites_Sequence(/* args */) : BTComposites_Sequence("BTComposites_Sequence"){};
        BTComposites_Sequence(std::string name);
        ~BTComposites_Sequence();
        NodeResult::BTResult ExecuteTask() override;
    };

    BTComposites_Sequence::BTComposites_Sequence(std::string name)
    {
        this->bt_name = name;
    }

    BTComposites_Sequence::~BTComposites_Sequence()
    {
    }

    inline NodeResult::BTResult BTComposites_Sequence::ExecuteTask()
    {
        for (auto &child : m_children)
        {
            NodeResult::BTResult result = child->ExecuteTask();
            if (result == NodeResult::BTResult::FAILURE)
            {
                return NodeResult::BTResult::FAILURE;
            }
        }
        return NodeResult::BTResult::SUCCESS;
    }

} // namespace BT
