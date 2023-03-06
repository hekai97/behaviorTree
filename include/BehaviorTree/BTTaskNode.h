#pragma once
#include "BTNode.h"
namespace BT
{
    class BTTaskNode : public BTNode
    {
    private:
        /* data */
        enum BTTaskNodeResult
        {
            BTTaskNodeResult_initialize,    // 任务初始化
            BTTaskNodeResult_Success,       // 任务成功
            BTTaskNodeResult_Failure,       // 任务失败
            BTTaskNodeResult_Running        // 任务正在执行
        };
    protected:
        // 任务的执行状态，如果任务正在执行，则返回BTTaskNodeResult_Running并且不会再次执行，直到任务完成
        BTTaskNodeResult t_result;
    public:
        BTTaskNode(/* args */);
        BTTaskNode(std::string name);
        ~BTTaskNode();
        NodeResult::BTResult ExecuteTask() override;
        BTNodeType getType() const override final;
    };


} // namespace BT
