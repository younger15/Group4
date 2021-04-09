#include"./OperateData.h"

class ResponseParser{

    static OperateData ParseHeader(std::string response);
    static OperateData ParseData(std::string response);
};