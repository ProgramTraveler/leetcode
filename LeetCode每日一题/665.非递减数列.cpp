/*
 * @lc app=leetcode.cn id=665 lang=cpp
 *
 * [665] 非递减数列
 */

// @lc code=start
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0; //记录替换的次数
        for (int i = 1; i < nums.size(); i ++) {
            //当出现前一个数字比后一个数字大，分两种情况讨论
            if (nums[i] < nums[i - 1]) { 
                //如果当前数字比前一个数字小，但比前两个数字大
                if (i ==1 || nums[i] >= nums[i - 2])
                    nums[i - 1] = nums[i]; //前一个数字就变成当前数字
                else
                    nums[i] = nums[i - 1]; //否则当前的数字就变成当前的数字
                //替换次数加一
                count ++;
            }
        }
        //返回判断结果
        return count <= 1;
    }
};
// @lc code=end

