#include "BehaviorTree/BTCompositesNode.h"
namespace BT
{
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

    inline void BTCompositesNode::AddChild(BTNode* child)
    {
        m_children.push_back(std::shared_ptr<BTNode>(child));
    }

    inline std::vector<std::shared_ptr<BTNode>> BTCompositesNode::GetChildren() const
    {
        return m_children;
    }
    inline NodeResult::BTResult BTCompositesNode::ExecuteTask()
    {
        return NodeResult::BTResult();
    }
} // namespace BT
