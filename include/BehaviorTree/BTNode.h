#pragma once
#include "BehaviorTreeType.h"
#include <string>

namespace BT
{

    class BTNode
    {
    private:
        /* data */
    protected:
        std::string bt_name;
    public:
        BTNode(/* args */);
        BTNode(std::string name);
        ~BTNode();
        virtual BTNodeType getType() const = 0;
        virtual NodeResult::BTResult ExecuteTask() = 0;
        virtual void setName(std::string name);
        virtual std::string getName() const;
    };

} // namespace BT
