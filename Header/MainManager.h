#include"./HttpListener.h"
#include"./RequestHandler.h"
#include"./SocketProcess.h"

class MainManager{

public:
    void NewRequest();
    void EndRequest();
    std::vector<SocketProcess*> sockets;
private:
    HttpListener listener;
    RequestHandler request;

};