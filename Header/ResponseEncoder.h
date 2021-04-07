#include<string>
#include"./OperateData.h"

class ResponseEncoder{

public:
    static std::string Encode(OperateData head, OperateData body);
};