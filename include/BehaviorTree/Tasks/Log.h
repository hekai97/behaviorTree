#pragma once
#include "BehaviorTree/BTTaskNode.h"
class Log : public BT::BTTaskNode
{
private:
    /* data */
public:
    Log(/* args */);
    ~Log();
    NodeResult::BTResult ExecuteTask() override;
};

Log::Log(/* args */)
{
}

Log::~Log()
{
}
