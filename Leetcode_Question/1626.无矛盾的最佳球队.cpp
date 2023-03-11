/*
 * @lc app=leetcode.cn id=1626 lang=cpp
 *
 * [1626] 无矛盾的最佳球队
 */

// @lc code=start
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<int> order(n);
        for (int i = 0; i < n; ++i)
            order[i] = i;
        sort(order.begin(), order.end(), [&](int i, int j){
            return ages[i] < ages[j] || (ages[i] == ages[j] && scores[i] < scores[j]);
        });
        vector<int> dp(n);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int idx = order[i];
            dp[i] = scores[idx];
            for (int j = 0; j < i; ++j) {
                int last = order[j];
                if (scores[last] <= scores[idx])
                    dp[i] = max(dp[i], dp[j] + scores[idx]);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
// @lc code=end

