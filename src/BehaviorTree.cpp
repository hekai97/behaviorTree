#include "BehaviorTree/BehaviorTree.h"
namespace BT
{
        BehaviorTree::BehaviorTree(/* args */)
    {
    }

    BehaviorTree::~BehaviorTree()
    {
    }

    BehaviorTree::NodePtr BehaviorTree::GetRootNode()
    {
        return rootNode;
    }

    void BehaviorTree::SetRootNode(BTCompositesNode* node)
    {
        rootNode = std::shared_ptr<BTCompositesNode>(node);
    }

    BlackBoard BehaviorTree::GetBlackBoard() const
    {
        return blackBoard;
    }

    NodeResult::BTResult BehaviorTree::runBehaviorTree()
    {
        return rootNode->ExecuteTask();
    }
} // namespace BT
