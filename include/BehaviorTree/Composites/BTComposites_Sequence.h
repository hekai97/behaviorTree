#pragma once
#include "BehaviorTree/BTCompositesNode.h"
namespace BT
{
    class BTComposites_Sequence : public BTCompositesNode
    {
    private:
        /* data */
    public:
        BTComposites_Sequence(/* args */);
        BTComposites_Sequence(std::string name);
        ~BTComposites_Sequence();
        NodeResult::BTResult ExecuteTask() override;
    };

    

} // namespace BT
