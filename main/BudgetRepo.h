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
            budget_amount += getOverlappingAmount(start, end, budget);
        }

        return budget_amount;
    }

    uint getOverlappingAmount(const year_month_day &start, const year_month_day &end, const Budget &budget) {
        return budget.amount /
               static_cast<uint>((budget.year_month_day.year() / budget.year_month_day.month() / last).day()) *
               getOverlappingDayCount(start, end,
                                      budget.year_month_day.year() / budget.year_month_day.month());
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

    std::vector<Budget> budgets_;
};

#endif /* MAIN_BUDGETREPO */
