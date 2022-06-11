/*
 * @lc app=leetcode.cn id=926 lang=cpp
 *
 * [926] 将字符串翻转到单调递增
 */

// @lc code=start
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int dp = 0;
        if (s.size() == 1) return dp;

        int count = 0;

        if (s[0] == '1') count = 1;
        for (int i = 1; i < s.size(); i ++) {
            if (s[i] == '1') count ++;
            else dp = min(dp + 1, count);
        }
        return dp;
    }
};
// @lc code=end

