# pragma once

enum class BTResult{
    SUCCESS,
    FAILURE,
    RUNNING
};

enum class BTNodeType{
    COMPOSITE,
    DECORATOR,
    ACTION,
    CONDITION
};



class BTNode
{
private:
    /* data */
public:
    BTNode(/* args */);
    ~BTNode();
    virtual BTNodeType getType() const = 0;
};

BTNode::BTNode(/* args */)
{
}

BTNode::~BTNode()
{
}
