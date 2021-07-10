/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //定义左右指针
        int left = 0, right = 0;
        //开始从头遍历
        while (right<nums.size()) {
            //如果当前数不为0，将左指针的数和右指针的数进行交换
            if (nums[right]!=0) {
                //cout<<nums[right]<<endl;
                swap(nums[left], nums[right]);
                //左指针移动
                left++;
            }
            //右指针移动
            right++;
        }
    }
};

// @lc code=end

