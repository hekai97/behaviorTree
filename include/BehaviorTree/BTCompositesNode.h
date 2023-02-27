#pragma once

#include <vector>
#include <memory>
#include "BTNode.h"
namespace BT
{

    class BTCompositesNode : public BTNode
    {
    protected:
        /* data */
        std::vector<std::shared_ptr<BTNode>> m_children;
    public:
        BTCompositesNode(/* args */);
        ~BTCompositesNode();
        BTNodeType getType() const override final;
        virtual void AddChild(BTNode* child);
        std::vector<std::shared_ptr<BTNode>> GetChildren() const;
        virtual NodeResult::BTResult ExecuteTask() override;
    };
} // namespace BT
