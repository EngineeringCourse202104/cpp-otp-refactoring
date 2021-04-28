#ifndef CPP_OTP_RSATOKENDAO_H
#define CPP_OTP_RSATOKENDAO_H

#include <string>

class RsaTokenDao
{

  public:
    std::string getRandom(std::string userName);
};

#endif  // CPP_OTP_RSATOKENDAO_H
