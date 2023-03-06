#pragma once
namespace NodeResult
{
    enum class BTResult
    {
        SUCCESS,
        FAILURE,
        RUNNING
    };
}
namespace BT
{
    enum class BTNodeType
    {
        COMPOSITE,
        DECORATOR,
        ACTION,
    };
} // namespace BT
