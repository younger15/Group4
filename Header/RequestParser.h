#include"./OperateData.h"

class RequestParser{

    static OperateData ParseHeader(std::string request);
    static OperateData ParseData(std::string request);
};