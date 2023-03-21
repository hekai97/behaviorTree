#include "BehaviorTree/BehaviorTree.h"
namespace BT
{
    BehaviorTree::BehaviorTree(/* args */)
    {
    }

    BehaviorTree::~BehaviorTree()
    {
    }

    void BehaviorTree::SetBlackBoard(BlackBoard *blackBoard)
    {
        this->blackBoard = std::shared_ptr<BlackBoard>(blackBoard);
    }
    BehaviorTree::NodePtr BehaviorTree::GetRootNode()
    {
        return rootNode;
    }

    void BehaviorTree::SetRootNode(BTCompositesNode* node)
    {
        rootNode = std::shared_ptr<BTCompositesNode>(node);
    }

    BehaviorTree::BlackBoardPtr BehaviorTree::GetBlackBoard() const
    {
        return blackBoard;
    }

    NodeResult::BTResult BehaviorTree::runBehaviorTree()
    {
        return rootNode->ExecuteTask();
    }
} // namespace BT
