/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        //找到左边的较小数
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        //将左边的数和右边的数教交换，再反转剩下的，如果i=0，直接反转
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= 0 && nums[i] >= nums[j]) {
                j--;
            }
            //交换
            swap(nums[i], nums[j]);
        }
        //反转
        reverse(nums.begin() + i + 1, nums.end());
    }
};

// @lc code=end

