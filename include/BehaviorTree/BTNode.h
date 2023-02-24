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
        BTNode(/* args */) : BTNode("BTNode"){};
        BTNode(std::string name);
        ~BTNode();
        virtual BTNodeType getType() const = 0;
        virtual NodeResult::BTResult ExecuteTask() = 0;
        void setName(std::string name);
        std::string getName() const;
    };

    BTNode::BTNode(std::string name)
    {
        bt_name = name;
    }

    BTNode::~BTNode()
    {
    }

    inline void BTNode::setName(std::string name)
    {
        bt_name = name;
    }

    inline std::string BTNode::getName() const
    {
        return bt_name;
    }


} // namespace BT
