/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
     {
        int n=nums.size();
        vector<int> dp(n,0);
        if(n<1)
        {
            return 0;
        }
        dp[0]=1;
        int MaxLength=1;
        for(int i=0;i<n;i++)
        {
            dp[i]=1;
            for(int j=0;j<n;j++)
            {
                if(nums[i]>nums[j])
                {
                    dp[i]=max(dp[i],dp[j]+1);
                }
                MaxLength=max(MaxLength,dp[i]);
            }
        }
        return MaxLength;
    }
};
// @lc code=end

