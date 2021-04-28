#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "../main/AuthenticationService.h"
#include "../main/LogPrinter.h"
#include "../main/RsaTokenDao.h"

namespace
{

struct LoggerMock : ILogPrinter
{
    MOCK_METHOD(void, log, (const std::string& msg), (override));
};

TEST(AuthenticationService, IsValid)
{
    // LogPrinter logger;
    LoggerMock logger;
    EXPECT_CALL(logger, log("login faild!")).Times(testing::AtLeast(1));
    std::string userName = "joey";
    RsaTokenDao rsaToken;
    auto token = rsaToken.getRandom(userName);
    AuthenticationService target(token, logger);
    bool actual = target.isValid(userName, "91");

    ASSERT_FALSE(actual);
}

}  // namespace