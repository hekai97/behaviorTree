#include "BehaviorTree/Composites/BTComposites_Parallel.h"
namespace BT
{

    BTComposites_Parallel::BTComposites_Parallel(/* args */): BTComposites_Parallel("BTComposites_Parallel")
    {
        
    }

    BTComposites_Parallel::BTComposites_Parallel(std::string name)
    {
        this->bt_name = name;
    }

    BTComposites_Parallel::~BTComposites_Parallel()
    {
    }

    inline NodeResult::BTResult BTComposites_Parallel::ExecuteTask()
    {
        std::vector<std::thread> threads;
        for (auto &child : m_children)
        {
            threads.push_back(std::thread(&BTNode::ExecuteTask, child));
        }
        for (auto &thread : threads)
        {
            thread.join();
        }
        return NodeResult::BTResult::SUCCESS;
    }
} // namespace BT
