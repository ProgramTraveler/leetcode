/*
 * @lc app=leetcode.cn id=2347 lang=cpp
 *
 * [2347] 最好的扑克手牌
 */

// @lc code=start
class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        unordered_map<int, int> count;
        unordered_map<int, int> al;

        for (int i = 0; i < ranks.size(); i ++) count[ranks[i]] ++;
        for (int i = 0; i < suits.size(); i ++) al[suits[i]] ++;

        int idx_1 = INT_MIN, idx_2 = INT_MIN;

        for (auto [k, v] : count) idx_1 = max(v, idx_1);

        for (auto [k, v] : al) idx_2 = max(v, idx_2);

        if (idx_2 == 5) return "Flush"; // 同花

        else if (idx_1 >= 3) return "Three of a Kind"; // 三条

        else if (idx_1 == 2) return "Pair"; // 对子

        else return "High Card"; // 高牌
    }
};
// @lc code=end

