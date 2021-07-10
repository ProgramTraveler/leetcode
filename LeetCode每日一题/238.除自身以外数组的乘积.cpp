/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
     {
         vector<int>output(nums.size(),1);
         int Left=1;
         int Right=1;
         for(int i=0;i<nums.size();i++)
         {
             output[i]*=Left;
             Left*=nums[i];

         }
         for(int j=nums.size()-1;j>=0;j--)
         {
             output[j]*=Right;
             Right*=nums[j];
         }
         return output;
    }
};
// @lc code=end

