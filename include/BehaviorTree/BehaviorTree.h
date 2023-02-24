#pragma once
#include <memory>
#include "BTNode.h"
#include "Blackboard/BlackBoard.h"
#include "BTCompositesNode.h"

namespace BT
{
    class BlackBoardData;
    class BehaviorTree
    {
        using NodePtr = std::shared_ptr<BTCompositesNode>;
    private:
        // 根节点
        NodePtr rootNode;
        // 黑板
        BlackBoard blackBoard;
    public:
        BehaviorTree(/* args */);
        ~BehaviorTree();
        NodePtr GetRootNode();
        BlackBoard GetBlackBoard() const;
        void SetRootNode(BTCompositesNode* node);
        NodeResult::BTResult runBehaviorTree();
    };

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
}
