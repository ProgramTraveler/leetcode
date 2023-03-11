/*
 * @lc app=leetcode.cn id=2283 lang=cpp
 *
 * [2283] 判断一个数的数字计数是否等于数位的值
 */

// @lc code=start
class Solution {
public:
    bool digitCount(string num) {
        unordered_map<int, int> ma;

        for (auto n : num) ma[n - '0'] ++;

        for (int i = 0; i < num.size(); i ++) if (ma[i] != (num[i] - '0')) return false;

        return true;
    }
};
// @lc code=end

