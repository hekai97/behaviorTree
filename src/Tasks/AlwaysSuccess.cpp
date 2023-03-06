#include "BehaviorTree/Tasks/AlwaysSuccess.h"

AlwaysSuccess::AlwaysSuccess(/* args */)
{
}
NodeResult::BTResult AlwaysSuccess::ExecuteTask()
{
    return NodeResult::BTResult::SUCCESS;
}