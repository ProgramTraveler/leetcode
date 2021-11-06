/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
 */

// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = n * (n + 1) >> 1;
        for (int i = 0; i < n; i ++) {
            res -= nums[i];
        }
        return res;
    }
};
// @lc code=end

