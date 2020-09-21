/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 缺失数字
 */

// @lc code=start

//感觉异或对这种类型的太好解了
class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int res = nums.size();
        for(int i = 0; i < nums.size(); ++i)
            res = res ^ i ^ nums[i];            // a^b^b = a;
        return res ;
    }
};
// @lc code=end

