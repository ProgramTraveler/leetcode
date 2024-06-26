/*
 * @lc app=leetcode.cn id=2741 lang=cpp
 *
 * [2741] 特别的排列
 */

// @lc code=start
class Solution {
public:
    int specialPerm(vector<int>& nums) {
        int n = nums.size(), u = (1 << n) - 1;
        vector<vector<long long>> memo(u, vector<long long>(n, -1)); // -1 表示没有计算过
        auto dfs = [&](auto&& dfs, int s, int i) -> long long {
            if (s == 0) {
                return 1; // 找到一个特别排列
            }
            auto& res = memo[s][i]; // 注意这里是引用
            if (res != -1) { // 之前计算过
                return res;
            }
            res = 0;
            for (int j = 0; j < n; j++) {
                if ((s >> j & 1) && (nums[i] % nums[j] == 0 || nums[j] % nums[i] == 0)) {
                    res += dfs(dfs, s ^ (1 << j), j);
                }
            }
            return res;
        };
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += dfs(dfs, u ^ (1 << i), i);
        }
        return ans % 1'000'000'007;
    }
};
// @lc code=end

