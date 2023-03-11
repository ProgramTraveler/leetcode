/*
 * @lc app=leetcode.cn id=775 lang=cpp
 *
 * [775] 全局倒置与局部倒置
 */

// @lc code=start
class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        // 这道题通过求非局部倒置来倒推结果的思路很不错 逆向思路
        // 而且看时间复杂度用朴素的方式是一定会超时的
        // 关键还是非局部倒置怎么判断

        int n = nums.size(), minSuff = nums[n - 1];

        for (int i = n -3; i >= 0; i --) {
            if (nums[i] > minSuff) return false;

            minSuff = min(nums[i + 1], minSuff);
        }

        return true;
    }
};
// @lc code=end

