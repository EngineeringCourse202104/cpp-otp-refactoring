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
            map_budgets_[budget.year_month_day.year()][budget.year_month_day.month()] = budget.amount;
            // std::cout << "map_budgets_: " << map_budgets_[2020_y][month(6)] << std::endl;
        }
    }
    int queryBudget(const date::year_month_day& start, const date::year_month_day& end)
    {

        if (budgets_.empty() || !start.ok() || !end.ok())
            return 0;

        if (end < start)
            return 0;

        int budget_amount = 0;
        auto curr_month = start.month();
        auto curr_year = start.year();
        for (; curr_year < end.year(); ++curr_year)
        {
            while (curr_month <= month(12))
            {
                budget_amount += map_budgets_[curr_year][curr_month];
                if (curr_month == month(12))
                {
                    break;
                }
                curr_month++;
                // std::cout << "curr_year: " << curr_year << ", month" << curr_month << std::endl;
            }
            // std::cout << " out while" << std::endl;
            curr_month = month(1);
        }
        while (curr_month < end.month())
        {
            budget_amount += map_budgets_[curr_year][curr_month];
            curr_month++;
        }

        int days_in_end_month = DaysInMonth(end);
        int days_in_start_month = DaysInMonth(start);
        budget_amount -=
            map_budgets_[curr_year][start.month()] / days_in_start_month * dateDateToIntDay((--start.day()));
        budget_amount += map_budgets_[curr_year][end.month()] / days_in_end_month * dateDateToIntDay(end.day());

        return budget_amount;
    }

    std::vector<Budget> findAll() { return budgets_; }

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
    std::map<date::year, std::map<date::month, int>> map_budgets_;
    std::vector<Budget> budgets_;
};

#endif /* MAIN_BUDGETREPO */