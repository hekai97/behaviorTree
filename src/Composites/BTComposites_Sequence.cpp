#include "BehaviorTree/Composites/BTComposites_Sequence.h"

namespace BT
{
    BTComposites_Sequence::BTComposites_Sequence(/* args */): BTComposites_Sequence("BTComposites_Sequence")
    {
    }
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
