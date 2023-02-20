#include <gtest/gtest.h>
#include "BehaviorTree/Composites/BTComposites_Parallel.h"
#include "BehaviorTree/Composites/BTComposites_Selector.h"
#include "BehaviorTree/Composites/BTComposites_Sequence.h"
#include "BehaviorTree/Blackboard/BlackBoard.h"
#include "BehaviorTree/BTTaskNode.h"

TEST(BehaviorTree, Blackboard)
{
    BlackBoard blackboard;
    blackboard.setValue("test", 1);
    EXPECT_EQ(blackboard.getValue<int>("test"), 1);
}

TEST(BehaviorTree, parallel)
{
    BT::BTComposites_Parallel parallel;
    EXPECT_EQ(parallel.getType(), BT::BTNodeType::COMPOSITE);
}

TEST(BehaviorTree, selector)
{
    BT::BTComposites_Selector selector;
    EXPECT_EQ(selector.getType(), BT::BTNodeType::COMPOSITE);
}

TEST(BehaviorTree, sequence)
{
    BT::BTComposites_Sequence sequence;
    EXPECT_EQ(sequence.getType(), BT::BTNodeType::COMPOSITE);
}

class TestTask : public BT::BTTaskNode
{
public:
    NodeResult::BTResult ExecuteTask() override;
};

NodeResult::BTResult TestTask::ExecuteTask()
{
    std::cout << "TestTask" << std::endl;
    return NodeResult::BTResult::SUCCESS;
}

TEST(BehaviorTree, task)
{
    TestTask task;
    EXPECT_EQ(task.getType(), BT::BTNodeType::ACTION);
    EXPECT_EQ(task.ExecuteTask(), NodeResult::BTResult::SUCCESS);
}

TEST(BehaviorTree,dynamic)
{
    BT::BTTaskNode* taskNode = new TestTask();
    TestTask* testTask = dynamic_cast<TestTask*>(taskNode);
    EXPECT_EQ(testTask->getType(), BT::BTNodeType::ACTION);
    EXPECT_EQ(testTask->ExecuteTask(), NodeResult::BTResult::SUCCESS);
}
