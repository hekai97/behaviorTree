#pragma once
#include "BehaviorTree/BTCompositesNode.h"

namespace BT
{
    class BTComposites_Selector : public BTCompositesNode
    {
    private:
        /* data */
    public:
        BTComposites_Selector(/* args */);
        BTComposites_Selector(std::string name);
        ~BTComposites_Selector();
        NodeResult::BTResult ExecuteTask() override;
    };
} // namespace BT
