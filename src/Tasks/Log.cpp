#include "BehaviorTree/Tasks/Log.h"
#include <iostream>
NodeResult::BTResult Log::ExecuteTask()
{
    std::cout << "Log: " << "TaskRunning" << std::endl;
    return NodeResult::BTResult::SUCCESS;
}