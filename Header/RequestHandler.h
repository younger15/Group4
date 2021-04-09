#include"./OperateData.h"
#include"./Authenticator.h"
#include"./APIHandler.h"

class RequestHandler{

public:
    Authenticator auth;
    OperateData *data;
    OperateData *header;
    std::unordered_map<std::string, APIHandler> apis;
};