/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        //定义一个动态数组，dp[i][j]表示到（i，j）这个点一共有多少条路径
        vector<vector<int>>dp(m,vector<int>(n,0));
        //因为在起点的横竖只有一条路径（机器人只能往下和右走），所以路径和为1
        for(int i=0;i<m;i++){dp[i][0]=1;}
        for(int j=0;j<n;j++){dp[0][j]=1;}
        //然后就求到达（i，j）这个点有多少条路径，因为这个点只能从上一个点或者下一个点到达
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        //返回最下角的那个点的路径
        return dp[m-1][n-1];
    }
};
// @lc code=end

