/*
 * @lc app=leetcode.cn id=463 lang=cpp
 *
 * [463] 岛屿的周长
 */

// @lc code=start
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans=0;
        //直接对数组进行遍历
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                //如果当前值是个岛屿
                if(grid[i][j]==1){
                    //就去向上下左右开始查找，边界或者是水的话ans加一
                    if(i-1<0 || grid[i-1][j]==0) ans++;
                    if(i+1==grid.size() || grid[i+1][j]==0) ans++;
                    if(j-1<0 || grid[i][j-1]==0) ans++;
                    if(j+1==grid[i].size() || grid[i][j+1]==0) ans++;
                }
            }

        }
        return ans;


    }
};
// @lc code=end

