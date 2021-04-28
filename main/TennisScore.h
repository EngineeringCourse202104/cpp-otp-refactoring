#ifndef MAIN_TENNISSCORE
#define MAIN_TENNISSCORE

#include <string>
#include <unordered_map>
class TennisScore
{
  public:
    void callPalerA() { player_score_a_ += 1; }
    void callPalerB() { player_score_b_ += 1; }
    std::string getScores()
    {
        if (player_score_a_ == player_score_b_ && (player_score_a_ == 3 || player_score_a_ == 4))
            return "Deuce";
        if (player_score_a_ == player_score_b_)
            return map_socre_[player_score_a_] + " All";

        if (player_score_a_ >= 4 && player_score_a_ >= player_score_b_ + 2)
            return player_a_name_ + " Win";
        else if (player_score_a_ >= 4 && player_score_a_ > player_score_b_)
            return player_a_name_ + " Adv";

        if (player_score_b_ >= 4 && player_score_b_ >= player_score_a_ + 2)
            return player_b_name_ + " Win";
        else if (player_score_b_ >= 4 && player_score_b_ > player_score_a_)
            return player_b_name_ + " Adv";

        return map_socre_[player_score_a_] + " " + map_socre_[player_score_b_];
    }
    TennisScore(const std::string& player_a_name, const std::string& player_b_name)
    {
        player_a_name_ = player_a_name;
        player_b_name_ = player_b_name;
        map_socre_[0] = "Love";
        map_socre_[1] = "Fifteen";
        map_socre_[2] = "Thirty";
        map_socre_[3] = "Forty";
        map_socre_[-1] = "All";
    }
    TennisScore() {}

  protected:
    std::unordered_map<int, std::string> map_socre_;
    int player_score_a_{0};
    int player_score_b_{0};
    std::string player_a_name_ = "";
    std::string player_b_name_ = "";
};

#endif /* MAIN_TENNISSCORE */
