#pragma once
#include <memory>
#include "BTNode.h"
namespace BT
{
    class BlackBoardData;
    class BehaviorTree
    {
        using NodePtr = std::shared_ptr<BTNode>;
    private:
        // 根节点
        NodePtr rootNode;
        // 黑板
        NodePtr blackBoard;
    public:
        BehaviorTree(/* args */);
        ~BehaviorTree();
        virtual NodePtr GetRootNode() = 0;
        virtual NodePtr GetBlackBoard() = 0;
    };

    BehaviorTree::BehaviorTree(/* args */)
    {
    }

    BehaviorTree::~BehaviorTree()
    {
    }
}
