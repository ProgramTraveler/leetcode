/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0, right = 0;
        while (right < nums.size()) {
            if (nums[right] != 0) { //当前元素非0
                swap(nums[left], nums[right]); //交换左右两指针的数
                left ++;
            }
            right ++;
        }
    }
};
// @lc code=end

