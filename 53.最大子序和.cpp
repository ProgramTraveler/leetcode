/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> dp(n,0);
        dp[0]=nums[0];
        int MaxSum=nums[0];
        for(int i=1;i<n;i++)
        {
            dp[i]=max(nums[i]+dp[i-1],nums[i]);
            MaxSum=A(dp[i],MaxSum);
        }
        return MaxSum;
    }
    int A(int a,int b)
    {
        if(a>b) return a;
        else return b;
    }
};
// @lc code=end

