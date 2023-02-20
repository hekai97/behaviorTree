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
        void AddChild(std::shared_ptr<BTNode> child);
        std::vector<std::shared_ptr<BTNode>> GetChildren() const;
    };

    BTCompositesNode::BTCompositesNode(/* args */)
    {
    }

    BTCompositesNode::~BTCompositesNode()
    {
    }

    BTNodeType BTCompositesNode::getType() const
    {
        return BTNodeType::COMPOSITE;
    }

    inline void BTCompositesNode::AddChild(std::shared_ptr<BTNode> child)
    {
        m_children.push_back(child);
    }

    inline std::vector<std::shared_ptr<BTNode>> BTCompositesNode::GetChildren() const
    {
        return m_children;
    }
} // namespace BT
