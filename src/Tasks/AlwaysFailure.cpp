#include "BehaviorTree/Tasks/AlwaysFailure.h"

AlwaysFailure::AlwaysFailure(/* args */)
{
}

AlwaysFailure::~AlwaysFailure()
{
}

NodeResult::BTResult AlwaysFailure::ExecuteTask()
{
    return NodeResult::BTResult::FAILURE;
}