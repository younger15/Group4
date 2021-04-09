#include<string>
#include"./OperateData.h"


class APIHandler{

public: 
    virtual void CallingAPI(OperateData data);
private:
    OperateData response;
    ResponseHandler responseHandle;
};