/*
 * @lc app=leetcode.cn id=918 lang=cpp
 *
 * [918] 环形子数组的最大和
 */

// @lc code=start
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // 组合问题老想用 dfs

        int max_s = INT_MIN; // 最大子数组和 不能为空
        int min_s = 0; // 最小子数组和 可以为空
        int max_f = 0, min_f = 0, sum = 0;

        for (int x : nums) {
            // 以 nums[i - 1] 结尾的子数组选或不选 (取 max) + x = 以 x 结尾的最大子数组和
            max_f = max(max_f, 0) + x;
            max_s = max(max_s, max_f);
            // 以 nums[i - 1] 结尾的子数组选或不选 (取 min) + x = 以 x 结尾的最小子数组和
            min_f = min(min_f, 0) + x;
            min_s = min(min_f, min_s);

            sum += x;
        }

        return sum == min_s ? max_s : max(max_s, sum - min_s);
    }
};
// @lc code=end

