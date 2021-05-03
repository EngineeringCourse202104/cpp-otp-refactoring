#ifndef MAIN_BUDGETREPO
#define MAIN_BUDGETREPO

#include <map>
#include <sstream>

#include "date.h"

struct Budget {
    date::year_month_day year_month_day{};
    int amount{0};
};

using namespace date;
using namespace std;

class BudgetRepo {
private:
    /* data */
public:
    BudgetRepo() {};

    BudgetRepo(const std::vector<Budget> &budgets) : budgets_(budgets) {
    }

    int queryBudget(const date::year_month_day &start, const date::year_month_day &end) {
        if (!start.ok() || !end.ok())
            return 0;

        int budget_amount = 0;

        for (const auto &budget : budgets_) {
            budget_amount +=
                    budget.amount /
                    DaysInMonth(budget.year_month_day.year() / budget.year_month_day.month() / 1) *
                    getOverlappingDayCount(start, end,
                                           budget.year_month_day.year() / budget.year_month_day.month());
        }

        return budget_amount;
    }

private:
    int getOverlappingDayCount(const year_month_day &start, const year_month_day &end, const year_month &budgetMonth) {
        auto overlappingStart = max(start, budgetMonth / 1);
        auto overlappingEnd = min(end, static_cast<year_month_day>(budgetMonth / last));
        if (overlappingStart > overlappingEnd) {
            return 0;
        }
        return (overlappingEnd.day() - overlappingStart.day()).count() + 1;
    }

    int DaysInMonth(const date::year_month_day &ymd) {
        return (uint) (ymd.year() / ymd.month() / last).day();
    }

    std::vector<Budget> budgets_;
};

#endif /* MAIN_BUDGETREPO */
