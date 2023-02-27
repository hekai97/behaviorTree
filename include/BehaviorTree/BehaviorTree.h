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
}
