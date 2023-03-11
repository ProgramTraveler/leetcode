/*
 * @lc app=leetcode.cn id=2335 lang=cpp
 *
 * [2335] 装满杯子需要的最短总时长
 */

// @lc code=start
class Solution {
public:
    int fillCups(vector<int>& amount) { // 可以同时装
        sort(amount.begin(), amount.end());

        for (int i = 0; i < amount.size(); i ++) {
            if (amount[2] > (amount[0] + amount[1])) return amount[2];
        }

        return (accumulate(amount.begin(), amount.end(), 0) + 1) / 2;

        /*int res = 0;

        vector<int> it1, it2; // 记录奇数和偶数的杯数

        for (int i = 0; i < amount.size(); i ++) amount[i] / 2 == 0 ? it1.push_back(amount[i]) :  it2.push_back(amount[i]);
        
        sort(it1.begin(), it1.end());

        for (int i = 0; i < it2.size(); i ++) res += it2[i] / 2;

        if (amount.size() - it2.size() == 1) res += it1[0];

        else if (amount.size() - it2.size() == 2) res += (it1[0] + it1[1]) >> 1;

        else if (amount.size() - it2.size() == 3) res += (it1[1] + it1[2]) >> 1, res += it1[0];

        return res;*/
    }
};
// @lc code=end

