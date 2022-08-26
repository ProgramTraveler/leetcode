/*
 * @lc app=leetcode.cn id=1464 lang=cpp
 *
 * [1464] 数组中两元素的最大乘积
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        return (nums[n - 1] -1) * (nums[n - 2] - 1);
    }
};
// @lc code=end

