#include<string>
#include<unordered_map>

class OperateData{

public:
    std::string key;
    std::unordered_map<std::string, OperateData*> nextNode;
    std::string value;
};