/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除排序数组中的重复项 II
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 1, flag = 1;
        while (flag < nums.size()){
            if (nums[flag] == nums[flag - 1]) index ++;
            else index = 1;
           
            if (index == 3) {
               
                for (int j = flag; j < nums.size() - 1; j ++) {
                    nums[j] = nums[j + 1];
                }
                nums.pop_back();
                index = 1;
                flag = 1;
            }else
                flag ++;
        }
        return nums.size();
    }
};
// @lc code=end

