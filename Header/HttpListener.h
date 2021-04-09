#include<sys/socket.h>
#include"./MainManager.h"

class MainManager{};

class HttpListener{

public:
    void BindPort(int portNum);
private:
    MainManager* mainManager;
}