/*
 * @lc app=leetcode.cn id=1254 lang=cpp
 *
 * [1254] 统计封闭岛屿的数目
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<vector<int>>& grid, int x, int y) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[x].size() || grid[x][y]) return;

        grid[x][y] = 1;

        dfs(grid, x - 1, y);
        dfs(grid, x + 1, y);
        dfs(grid, x, y - 1);
        dfs(grid, x, y + 1);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; i ++) { // 将不是封闭的岛去除
            // 如果是 第一行 或者是 最后一行 就遍历这一行的所有格子
            // 否则就访问 第一列 和 最后一列

            int step = (i == 0 || i == m - 1) ? 1 : n - 1;
            for (int j = 0; j < n; j += step) dfs(grid, i, j);
        }

        int res = 0;

        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j] == 0) res ++, dfs(grid, i ,j); // 是 0 一定是封闭的
            }
        }

        return res;
    }
};
// @lc code=end

