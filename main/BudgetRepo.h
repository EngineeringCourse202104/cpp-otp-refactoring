#ifndef MAIN_BUDGETREPO
#define MAIN_BUDGETREPO

#include <map>
#include <sstream>
#include <numeric>

#include "date.h"

using namespace date;
using namespace std;

struct Budget {
    year_month_day month{};
    int amount{0};

    uint getOverlappingAmount(const year_month_day &start, const year_month_day &end) const {
        return amount * getOverlappingDayCount(start, end) /
               static_cast<uint>((month.year() / month.month() / last).day());
    }

private:
    int getOverlappingDayCount(const year_month_day &start, const year_month_day &end) const {
        auto overlappingStart = max(start, month);
        auto overlappingEnd = min(end, static_cast<year_month_day>(month.year() / month.month() / last));
        if (overlappingStart > overlappingEnd) {
            return 0;
        }
        return (overlappingEnd.day() - overlappingStart.day()).count() + 1;
    }

};

class BudgetRepo {
public:
    BudgetRepo() {};

    BudgetRepo(const std::vector<Budget> &budgets) : budgets_(budgets) {
    }

    int queryBudget(const date::year_month_day &start, const date::year_month_day &end) {
        if (!start.ok() || !end.ok())
            return 0;

        return std::accumulate(budgets_.begin(), budgets_.end(), 0, [&](int amount, const Budget &budget) {
            return amount + budget.getOverlappingAmount(start, end);
        });
    }

private:
    std::vector<Budget> budgets_;
};

#endif /* MAIN_BUDGETREPO */
