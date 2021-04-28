#include <string>

#include "gtest/gtest.h"
#include "main/TennisScore.h"
namespace
{

class TennisScoreFixture : public testing::Test
{
  public:
    virtual void SetUp()
    {
        const std::string player_a_name = "Joseph";
        const std::string player_b_name = "Chen";
        tennis_score_ = TennisScore(player_a_name, player_b_name);
    }

  protected:
    void InvokeCallPlayerAAndPlayerB(int NumsA, int NumsB)
    {
        for (int i = 0; i < NumsA; ++i)
        {
            tennis_score_.callPalerA();
        }
        for (int i = 0; i < NumsB; ++i)
        {
            tennis_score_.callPalerB();
        }
    }

  protected:
    TennisScore tennis_score_;
};

TEST_F(TennisScoreFixture, WhenEqualAsZero)
{
    InvokeCallPlayerAAndPlayerB(0, 0);

    EXPECT_EQ(tennis_score_.getScores(), "Love All");
}

TEST_F(TennisScoreFixture, IsFifteenLove)
{
    InvokeCallPlayerAAndPlayerB(1, 0);

    EXPECT_EQ(tennis_score_.getScores(), "Fifteen Love");
}

TEST_F(TennisScoreFixture, IsThirtyLove)
{
    InvokeCallPlayerAAndPlayerB(2, 0);
    EXPECT_EQ(tennis_score_.getScores(), "Thirty Love");
}

TEST_F(TennisScoreFixture, IsFortyLove)
{
    InvokeCallPlayerAAndPlayerB(3, 0);

    EXPECT_EQ(tennis_score_.getScores(), "Forty Love");
}

TEST_F(TennisScoreFixture, IsJosephWin)
{
    InvokeCallPlayerAAndPlayerB(4, 0);
    EXPECT_EQ(tennis_score_.getScores(), "Joseph Win");
}

TEST_F(TennisScoreFixture, IsFifteenAll)
{
    InvokeCallPlayerAAndPlayerB(1, 1);
    EXPECT_EQ(tennis_score_.getScores(), "Fifteen All");
}

TEST_F(TennisScoreFixture, IsJosephAdv)
{
    InvokeCallPlayerAAndPlayerB(4, 3);
    EXPECT_EQ(tennis_score_.getScores(), "Joseph Adv");
}

TEST_F(TennisScoreFixture, IsJosephAdvSixFive)
{
    InvokeCallPlayerAAndPlayerB(6, 5);
    EXPECT_EQ(tennis_score_.getScores(), "Joseph Adv");
}

TEST_F(TennisScoreFixture, IsJosephWinSevenFive)
{
    InvokeCallPlayerAAndPlayerB(7, 5);
    EXPECT_EQ(tennis_score_.getScores(), "Joseph Win");
}

TEST_F(TennisScoreFixture, IsChenAdvFiveSix)
{
    InvokeCallPlayerAAndPlayerB(5, 6);
    EXPECT_EQ(tennis_score_.getScores(), "Chen Adv");
}

TEST_F(TennisScoreFixture, IsChenWinFortyFortyTwo)
{
    InvokeCallPlayerAAndPlayerB(40, 42);
    EXPECT_EQ(tennis_score_.getScores(), "Chen Win");
}

}  // namespace