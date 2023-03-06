#pragma once
#include "BehaviorTree/BTTaskNode.h"

class AlwaysFailure : public BT::BTTaskNode
{
private:
    /* data */
public:
    AlwaysFailure(/* args */);
    ~AlwaysFailure();
    NodeResult::BTResult ExecuteTask() override;
};
