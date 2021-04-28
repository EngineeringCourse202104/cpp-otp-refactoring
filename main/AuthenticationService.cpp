//
// Created by Joseph Yao on 2018/7/31.
//

#include "AuthenticationService.h"

#include <iostream>
#include <string>

#include "ProfileDao.h"
#include "RsaTokenDao.h"

bool AuthenticationService::isValid(const std::string userName, const std::string password)
{
    // 根據 account 取得自訂密碼
    ProfileDao profileDao;
    auto passwordFromDao = profileDao.getPassword(userName);

    // 根據 account 取得 RSA token 目前的亂數

    // 驗證傳入的 password 是否等於自訂密碼 + RSA token亂數

    auto validPassword = passwordFromDao + randomCode_;

    auto isValid = password == validPassword;

    if (isValid)
    {
        return true;
    }
    else
    {
        // logger_.log("login faild!");
        return false;
    }
}
