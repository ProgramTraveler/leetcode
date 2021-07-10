/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        const int M = text1.size();
        const int N = text2.size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
        for (int i = 1; i <= M; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[M][N];
    }
};

// @lc code=end

