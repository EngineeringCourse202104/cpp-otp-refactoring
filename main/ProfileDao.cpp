#include "ProfileDao.h"

#include "Context.h"

std::string ProfileDao::getPassword(const std::string userName)
{
    return Context::getPassword(userName);
}
