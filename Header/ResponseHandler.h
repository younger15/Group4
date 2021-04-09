#include"./OperateData.h"
#include"./APIHandler.h"

class ResponseHandler{

public:
    void Send();
private:
    OperateData *data;
    OperateData *header;
    std::string response;
};