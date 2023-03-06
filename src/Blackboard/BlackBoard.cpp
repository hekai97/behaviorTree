// #include "BehaviorTree/Blackboard/BlackBoard.h"

// namespace BT
// {
//     template<typename T>
//     T BlackBoard::getValue(const std::string& key, const T& defaultValue = T()) const {
//         auto it = values.find(key);
//         if (it != values.end()) {
//             return boost::any_cast<T>(it->second);
//         }
//         return defaultValue;
//     }
//     template<typename T>
//     void BlackBoard::setValue(const std::string& key, const T& value) {
//         values[key] = value;
//     }
// } // namespace BT
