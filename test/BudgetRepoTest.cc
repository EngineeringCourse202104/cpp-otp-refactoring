#include <string>

#include "gtest/gtest.h"
#include "../main/BudgetRepo.h"

using namespace date;
class BudgetRepoTestFixture : public testing::Test
{
  public:
    void SetupDefaultBudge2()
    {
        std::vector<Budget> list_budget;

        Budget budget;
        budget.year_month_day = year_month_day{2019_y / 1 / 1};
        budget.amount = 31;
        list_budget.push_back(budget);

        budget.year_month_day = year_month_day{2019_y / 2 / 1};
        budget.amount = 280;
        list_budget.push_back(budget);
        budget.year_month_day = year_month_day{2019_y / 3 / 1};
        budget.amount = 310;
        list_budget.push_back(budget);
        budget.year_month_day = year_month_day{2019_y / 4 / 1};
        budget.amount = 30;
        list_budget.push_back(budget);

        budget_repo_ = BudgetRepo(list_budget);
    }

    void SetupDefaultBudge()
    {
        std::vector<Budget> list_budget;

        Budget budget;
        budget.year_month_day = year_month_day{2019_y / 1 / 1};
        budget.amount = 31;
        list_budget.push_back(budget);

        budget.year_month_day = year_month_day{2019_y / 2 / 1};
        budget.amount = 28;
        list_budget.push_back(budget);
        budget.year_month_day = year_month_day{2019_y / 3 / 1};
        budget.amount = 31;
        list_budget.push_back(budget);
        budget.year_month_day = year_month_day{2019_y / 4 / 1};
        budget.amount = 30;
        list_budget.push_back(budget);

        budget_repo_ = BudgetRepo(list_budget);
    }

  protected:
    BudgetRepo budget_repo_;
};

TEST_F(BudgetRepoTestFixture, InValidDate)
{
    SetupDefaultBudge();

    date::year_month_day start_data;
    date::year_month_day end_data;

    EXPECT_EQ(0, budget_repo_.queryBudget(start_data, end_data));
}

TEST_F(BudgetRepoTestFixture, InValidDateOfEndLargeThanStart)
{
    SetupDefaultBudge();

    date::year_month_day start_data = 2019_y / 4 / 1;
    date::year_month_day end_data = 2017_y / 4 / 1;

    EXPECT_EQ(0, budget_repo_.queryBudget(start_data, end_data));
}

TEST_F(BudgetRepoTestFixture, ValidDateFrom201741To201851)
{
    SetupDefaultBudge();

    date::year_month_day start_data = 2017_y / 4 / 1;
    date::year_month_day end_data = 2019_y / 5 / 1;

    EXPECT_EQ(120, budget_repo_.queryBudget(start_data, end_data));
}

TEST_F(BudgetRepoTestFixture, ValidDateSameDate)
{
    SetupDefaultBudge();

    date::year_month_day start_data = 2019_y / 4 / 1;
    date::year_month_day end_data = 2019_y / 4 / 1;

    EXPECT_EQ(1, budget_repo_.queryBudget(start_data, end_data));
}

TEST_F(BudgetRepoTestFixture, ValidDateFrom20190102To20190403)
{
    SetupDefaultBudge();

    date::year_month_day start_data = 2019_y / 1 / 2;
    date::year_month_day end_data = 2019_y / 4 / 3;

    EXPECT_EQ(92, budget_repo_.queryBudget(start_data, end_data));
}

TEST_F(BudgetRepoTestFixture, ValidDateFrom20190102To20190123)
{
    SetupDefaultBudge();

    date::year_month_day start_data = 2019_y / 1 / 2;
    date::year_month_day end_data = 2019_y / 1 / 23;

    EXPECT_EQ(22, budget_repo_.queryBudget(start_data, end_data));
}

TEST_F(BudgetRepoTestFixture, ValidDateFrom20190102To20190223WithBudge2)
{
    SetupDefaultBudge2();
    date::year_month_day start_data = 2019_y / 1 / 2;
    date::year_month_day end_data = 2019_y / 2 / 23;

    EXPECT_EQ(260, budget_repo_.queryBudget(start_data, end_data));
}