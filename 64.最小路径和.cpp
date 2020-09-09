/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int H=grid.size();
        int L=grid[0].size();
         vector<vector<int>> dp(grid);
        for(int i=0;i<H;i++)
        {
            for(int j=0;j<L;j++)
            {
                if(i==0 && j==0)
                {
                    dp[i][j]=grid[i][j];
                }
                else if(i==0 && j!=0)
                {
                    dp[i][j]=dp[i][j-1]+grid[i][j];
                }
                else if(i!=0 && j==0)
                {
                    dp[i][j]=dp[i-1][j]+grid[i][j];
                }
                else
                {
                    dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
                }
            }
        }
        return dp[H-1][L-1];
    }
};
// @lc code=end

