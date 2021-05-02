#ifndef MAIN_BUDGETREPO
#define MAIN_BUDGETREPO
#include <map>
#include <sstream>

#include "date.h"

struct Budget
{
    date::year_month_day year_month_day{};
    int amount{0};
};

using namespace date;
using namespace std;
class BudgetRepo
{
  private:
    /* data */
  public:
    BudgetRepo(){};
    BudgetRepo(const std::vector<Budget>& budgets) : budgets_(budgets)
    {
        for (const auto& budget : budgets_)
        {
            map_budgets_[budget.year_month_day] = budget;
        }
    }
    int queryBudget(const date::year_month_day& start, const date::year_month_day& end)
    {
        if (budgets_.empty() || !start.ok() || !end.ok())
            return 0;

        if (end < start)
            return 0;

        int budget_amount = 0;
        for (year_month current = start.year()/start.month(); current < end.year()/end.month(); current += months(1) )
        {
            budget_amount += getBudgetAmount(current.year(), current.month());
        }

        int days_in_end_month = DaysInMonth(end);
        int days_in_start_month = DaysInMonth(start);
        budget_amount -= getBudgetAmount(start.year(), start.month()) / days_in_start_month * dateDateToIntDay((--start.day()));
        budget_amount += getBudgetAmount(end.year(), end.month()) / days_in_end_month * dateDateToIntDay(end.day());

        return budget_amount;
    }

    int &getBudgetAmount(const year &curr_year, const month &curr_month) { return map_budgets_[curr_year/curr_month/1].amount; }

  protected:
    int dateDateToIntDay(const date::day& day)
    {
        int ret = 0;
        stringstream geek;
        geek << day;
        geek >> ret;
        return ret;
    }
    int DaysInMonth(const date::year_month_day& ymd)
    {
        int days_in_end_month;
        days_in_end_month = dateDateToIntDay((ymd.year() / ymd.month() / date::last).day());

        // std::cout << "days_in_end_month: " << days_in_end_month << std::endl;
        return days_in_end_month;
    }
    std::map<date::year_month_day, Budget> map_budgets_;
    std::vector<Budget> budgets_;
};

#endif /* MAIN_BUDGETREPO */
