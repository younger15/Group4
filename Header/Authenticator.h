#include<string>

class Authenticator{

public:
    bool CheckAccount(std::string account, std::string password);
    std::string SearchAccount(std::string account);
};