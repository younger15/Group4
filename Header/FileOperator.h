#include"./ResponseHandler.h"
#include"./OperateData.h"
#include<string>

class FileOperator{

public:
    void Upload(std::string path, std::string filename);
    std::string Download(std::string path);
    void Update(std::string path, OperateData updateInfo);
private:
    ResponseHandler response;
};