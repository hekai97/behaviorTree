#pragma once
#include <string>
#include <unordered_map>
#include <boost/any.hpp>
class BlackBoard {
public:
    template<typename T>
    T getValue(const std::string& key, const T& defaultValue = T()) const 
    {
        auto it = values.find(key);
        if (it != values.end()) {
            return boost::any_cast<T>(it->second);
        }
        return defaultValue;
    }
    template<typename T>
    void setValue(const std::string& key, const T& value)
    {
        values[key] = value;
    }
private:
    std::unordered_map<std::string, boost::any> values;
};