
#include <chrono>
#include <ctime>
#include <iostream>

#include "gtest/gtest.h"
#include "main/birthday.h"
#include "main/date.h"

using namespace date;

namespace
{
class BirthdayFiture : public testing::Test
{
  public:
    virtual void SetUp() {}

    date::year_month_day GetToday() { return 2013_y / 4 / 9; }
    void InvodeBirthday()
    {
        Birthday birth_day(GetToday());
        ret = birth_day.isBirthday();
    }

  protected:
    bool ret = false;
};

TEST_F(BirthdayFiture, IsValid)
{
    InvodeBirthday();
}

}  // namespace
