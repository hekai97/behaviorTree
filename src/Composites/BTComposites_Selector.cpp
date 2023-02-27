#include "BehaviorTree/Composites/BTComposites_Selector.h"
namespace BT
{
    BTComposites_Selector::BTComposites_Selector(/* args */): BTComposites_Selector("BTComposites_Selector")
    {
        
    }
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
