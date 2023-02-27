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
        BTComposites_Parallel(/* args */);
        BTComposites_Parallel(std::string name);
        ~BTComposites_Parallel();
        NodeResult::BTResult ExecuteTask() override;
    };
} // namespace BT
