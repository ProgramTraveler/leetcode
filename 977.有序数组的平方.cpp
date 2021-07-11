/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size(), 0); //记录最终的结果
        int fir = 0, las = nums.size() - 1; //记录开始和最后的位置
        int index = nums.size() - 1; //储存当前位置的指针
        while (fir <= las) {
            if (nums[fir] * nums[fir] > nums[las] * nums[las]) {
                ans[index] = nums[fir] * nums[fir];
                fir ++;
            }else {
                ans[index] = nums[las] * nums[las];
                las --;
            }
            index --;
        }
        return ans;
    }
};
// @lc code=end

