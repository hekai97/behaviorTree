#include <gtest/gtest.h>
#include "BehaviorTree/Composites/BTComposites_Parallel.h"
#include "BehaviorTree/Composites/BTComposites_Selector.h"
#include "BehaviorTree/Composites/BTComposites_Sequence.h"
#include "BehaviorTree/Blackboard/BlackBoard.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BehaviorTree/BehaviorTree.h"

#include "BehaviorTree/Tasks/AlwaysSuccess.h"

TEST(BehaviorTree, Blackboard)
{
    BlackBoard blackboard;
    blackboard.setValue("test", 1);
    EXPECT_EQ(blackboard.getValue<int>("test"), 1);
    // EXPECT_EQ(blackboard.getValue<int>("test2"), 0);
    AlwaysSuccess* task = new AlwaysSuccess();
    EXPECT_EQ(task->ExecuteTask(), NodeResult::BTResult::SUCCESS);
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

class TestTask2 : public BT::BTTaskNode
{
public:
    NodeResult::BTResult ExecuteTask() override; 
};

NodeResult::BTResult TestTask2::ExecuteTask()
{
    // 线程休眠2s
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "TestTask2" << std::endl;
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

TEST(BehaviorTree,parallelTask)
{
    BT::BTComposites_Parallel parallel;
    TestTask *taskNode = new TestTask();
    parallel.AddChild(taskNode);
    TestTask2 *taskNode2 = new TestTask2();
    parallel.AddChild(taskNode2);
    // parallel.ExecuteTask();
    EXPECT_EQ(parallel.getType(), BT::BTNodeType::COMPOSITE);
    EXPECT_EQ(parallel.ExecuteTask(), NodeResult::BTResult::SUCCESS);
}

TEST(BehaviorTree,BTTree)
{
    BT::BehaviorTree *tree = new BT::BehaviorTree();
    BT::BTComposites_Parallel *rootNode = new BT::BTComposites_Parallel();
    TestTask *taskNode = new TestTask();
    TestTask2 *taskNode2 = new TestTask2();
    rootNode->AddChild(taskNode);
    rootNode->AddChild(taskNode2);
    tree->SetRootNode(rootNode);
    EXPECT_EQ(tree->runBehaviorTree(), NodeResult::BTResult::SUCCESS);
}

TEST(BehaviorTree,BTName)
{
    BT::BTComposites_Parallel *rootNode = new BT::BTComposites_Parallel();
    EXPECT_EQ(rootNode->getName(), "BTComposites_Parallel");
}

TEST(BehaviorTree,Complete)
{
    BT::BehaviorTree *tree = new BT::BehaviorTree();
    BT::BTComposites_Selector *rootNode = new BT::BTComposites_Selector();
    TestTask *taskNode = new TestTask();
    taskNode->setName("task1");
    TestTask2 *taskNode2 = new TestTask2();
    taskNode2->setName("task2");
    rootNode->AddChild(taskNode);
    rootNode->AddChild(taskNode2);
    tree->SetRootNode(rootNode);
    EXPECT_EQ(tree->runBehaviorTree(), NodeResult::BTResult::SUCCESS);
}

