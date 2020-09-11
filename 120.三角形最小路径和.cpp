/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n=triangle.size();
        vector<vector<int>> dp(triangle);//初始化一个n*n的二维数组
        dp[0][0]=triangle[0][0];
        int MinSum=INT_MAX;
        if(n==1)
        {
            return dp[0][0];
        }
        else
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<dp[i].size();j++)
            {
                //如果有两个相邻的数
                if(j-1>=0 && j<dp[i-1].size())
                {
                    dp[i][j]=min(dp[i-1][j-1],dp[i-1][j])+triangle[i][j];
                }
                //在最右边的数只能继承左斜方的数
                else if(j-1>=0)
                {
                    dp[i][j]=dp[i-1][j-1]+triangle[i][j];
                }
                //在最左边的数只能继承来自上方的数
                else
                {
                    dp[i][j]=dp[i-1][j]+triangle[i][j];
                }
                if(i==n-1)
                {
                    if(dp[i][j]<MinSum)
                    {
                        MinSum=dp[i][j];
                    }
                }
            }
        }
        return MinSum;
    }
};
// @lc code=end

