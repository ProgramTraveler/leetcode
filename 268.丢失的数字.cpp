/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
 */

// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //简简单单做个差
        int n = nums.size();
        int res = n * (n + 1) >> 1;
        for (int i = 0; i < n; i ++) {
            res -= nums[i];
        }
        return res;
        /* 异或是最常用的方法
        int res = nums.size();
        for(int i = 0; i < nums.size(); ++ i)
            res = res ^ i ^ nums[i];            // a^b^b = a;
        return res ;
        */
    }
};
// @lc code=end

