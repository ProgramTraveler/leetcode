/*
 * @lc app=leetcode.cn id=1749 lang=cpp
 *
 * [1749] 任意子数组和的绝对值的最大值
 */

// @lc code=start
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        // 不知道 dfs 能不能过
        // 不能过就是 dp 了
        // 前缀和
        int res = 0;

        int n = nums.size();

        int f_max = 0, f_min = 0;

        for (int x : nums) {
            f_max = max(f_max, 0) + x;
            f_min = min(0, f_min) + x;

            res = max(res, max(f_max, - f_min));
        }
        
        return res;
    }
};
// @lc code=end

