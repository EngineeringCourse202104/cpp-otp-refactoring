#ifndef CPP_OTP_AUTHENTICATIONSERVICE_H
#define CPP_OTP_AUTHENTICATIONSERVICE_H

#include <string>

#include "LogPrinter.h"

class AuthenticationService
{
  public:
    AuthenticationService(const std::string& token, ILogPrinter& logger) : logger_(logger) { randomCode_ = token; }

  public:
    bool isValid(const std::string userName, const std::string password);

  protected:
    std::string randomCode_;
    ILogPrinter& logger_;
};

#endif  // CPP_OTP_AUTHENTICATIONSERVICE_H
