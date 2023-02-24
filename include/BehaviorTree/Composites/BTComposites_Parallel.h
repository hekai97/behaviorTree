#pragma once
#include <thread>
#include "BehaviorTree/BTCompositesNode.h"

namespace BT
{
    class BTComposites_Parallel : public BTCompositesNode
    {
    private:
        /* data */
    public:
        BTComposites_Parallel(/* args */) : BTComposites_Parallel("BTComposites_Parallel"){};
        BTComposites_Parallel(std::string name);
        ~BTComposites_Parallel();
        NodeResult::BTResult ExecuteTask() override;
    };

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
