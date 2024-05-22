/*
 * @lc app=leetcode.cn id=2225 lang=cpp
 *
 * [2225] 找出输掉零场或一场比赛的玩家
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
       std::unordered_map<int, int> win_cnt;
       for (const auto& matche : matches) {
        win_cnt[matche.front()] = 0;
        win_cnt[matche.back()] = 0;
       }
       for (const auto& matche : matches) {
        win_cnt[matche.back()] --;
       } 
       std::vector<std::vector<int>> res;
       std::vector<int> temp_1, temp_2;
       for (const auto& m : win_cnt) {
        if (m.second == 0) temp_1.emplace_back(m.first);
        if (m.second == -1) temp_2.emplace_back(m.first); 
       }
       ranges::sort(temp_1);
       ranges::sort(temp_2);
       res.emplace_back(temp_1);
       res.emplace_back(temp_2);
       return res;
    }
};
// @lc code=end

