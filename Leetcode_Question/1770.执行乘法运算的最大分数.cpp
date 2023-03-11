/*
 * @lc app=leetcode.cn id=1770 lang=cpp
 *
 * [1770] 执行乘法运算的最大分数
 */

// @lc code=start
class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        vector<vector<long long>> dp(1005, vector<long long>(1005, 0));
        long long m = multipliers.size(), res = INT_MIN, n = nums.size();
        for(int k = 1; k <= m; ++k){
            for(int i = 0; i <= k; i++){
                if(i == 0) dp[i][k - i] = dp[i][k - i - 1] + nums[n - k + i] * multipliers[k - 1];
                else if(i == k) dp[i][k - i] = dp[i - 1][k - i] + nums[i - 1] * multipliers[k - 1];
                else dp[i][k - i] = max(dp[i][k - i - 1] + nums[n - k + i] * multipliers[k - 1], dp[i - 1][k - i] + nums[i - 1] * multipliers[k - 1]);
                if(k == m) res = max(res, dp[i][k - i]);
            }
        }
        return res;
    }
};
// @lc code=end

