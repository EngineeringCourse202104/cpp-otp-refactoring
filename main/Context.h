#ifndef CPP_OTP_CONTEXT_H
#define CPP_OTP_CONTEXT_H

#include <map>
#include <string>

class Context
{

  public:
    Context();

    static std::string getPassword(std::string userName);

    static std::map<std::string, std::string> profiles;
};

#endif  // CPP_OTP_CONTEXT_H
