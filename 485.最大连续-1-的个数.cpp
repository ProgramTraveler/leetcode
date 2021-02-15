/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续1的个数
 */

// @lc code=start
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0; //记录数组中的最多的连续1的个数
        int index = 0; //记录窗口中1的个数
        int left = 0, right = 0; //窗口的边界
        //对数组中的1进行遍历处理
        while (right < nums.size()) {
            //如果窗口中的数都是1
            if (nums[right] == nums[left] && nums[left] == 1) {
                right ++; //扩大窗口
                index ++; //窗口个数加1
            }else {
                index = 0; //跟新窗口中1的个数
                left = right; //左窗口移到右窗口的位置
                //按照不同的情况来判断右窗口是否移动
                nums[right] == 1 ? right = right : right ++;
            }
            //随时记录窗口中1的个数
            res = max(res, index);
        }
        return res;
    }
};
// @lc code=end

