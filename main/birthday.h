#include <chrono>
#include <ctime>
#include <iostream>

#include "date.h"
using namespace std;

using namespace date;
class Birthday
{
  public:
    bool isBirthday()
    {
        date::year_month_day today;
        std::cout << today << std::endl;
        return date_birthday_ == today;
    }
    Birthday(const date::year_month_day& today)
    {
        date_birthday_ = today;
        std::cout << date_birthday_ << std::endl;
    }

  protected:
    date::year_month_day date_birthday_;
};