#pragma once
#include <memory>
#include "BTNode.h"
#include "Blackboard/BlackBoard.h"
#include "BTCompositesNode.h"

namespace BT
{
    class BehaviorTree
    {
        using NodePtr = std::shared_ptr<BTCompositesNode>;
        using BlackBoardPtr = std::shared_ptr<BlackBoard>;
    private:
        // 根节点
        NodePtr rootNode;
        // 黑板
        BlackBoardPtr blackBoard;
    public:
        BehaviorTree(/* args */);
        ~BehaviorTree();
        void SetBlackBoard(BlackBoard* blackBoard);
        BlackBoardPtr GetBlackBoard() const;
        NodePtr GetRootNode();
        void SetRootNode(BTCompositesNode* node);
        NodeResult::BTResult runBehaviorTree();
    };
}
