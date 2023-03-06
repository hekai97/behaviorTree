#pragma once
#include "BehaviorTree/BTTaskNode.h"

class AlwaysSuccess : public BT::BTTaskNode
{
private:
    /* data */
public:
    AlwaysSuccess(/* args */);
    ~AlwaysSuccess();
    NodeResult::BTResult ExecuteTask() override;
};

