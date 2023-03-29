/*
 * @lc app=leetcode.cn id=1641 lang=cpp
 *
 * [1641] 统计字典序元音字符串的数目
 */

// @lc code=start
class Solution {
public:
    int countVowelStrings(int n) {
        // 动态规划
        vector<int> dp(5, 1); // 初始状态为 5 个元音

        for (int i = 1; i < n; i ++) {
            for (int j = 1; j < 5; j ++) dp[j] += dp[j - 1];
        }

        return accumulate(dp.begin(), dp.end(), 0);
    }
};
// @lc code=end

