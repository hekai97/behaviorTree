#pragma once
#include "BTNode.h"
namespace BT
{
    class BTTaskNode : public BTNode
    {
    private:
        /* data */
    public:
        BTTaskNode(/* args */);
        BTTaskNode(std::string name);
        ~BTTaskNode();
        NodeResult::BTResult ExecuteTask() override;
        BTNodeType getType() const override final;
    };


} // namespace BT
