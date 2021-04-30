/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0, right = 2;
        while (right < nums.size()) {
            if (nums[left] != nums[right])
                break;
            else {
                left = right + 1;
                right = left + 2;
            }
        }
        return nums[left];
    }
};
// @lc code=end

