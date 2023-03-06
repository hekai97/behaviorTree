#pragma once
#include "BehaviorTree/BTTaskNode.h"

class Wait : public BT::BTTaskNode
{
private:
    /* data */
    float t_waitTime;
    // 随机等待的时间，作用为：让所有的Wait节点的等待时间不一样，避免同时等待，randomDeviation为随机偏移量
    float randomDeviation;
    
public:
    Wait(/* args */);
    ~Wait();
};
