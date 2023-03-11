/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
/*
    这是一个失败的方法 或者说是一个失败的思路 -> 这个方法本想通过深度遍历来找到每个岛屿以及相邻的岛屿 对探索过的岛屿进行标记 但是在设计的过程中发现 存在走回头和但环出现的时候存在无法正常统计的后果

    bool dfs (vector<vector<char>>& grid, vector<vector<bool>>& ma, int row, int col, int max_r, int max_c, string st) {
        if (row < 0 || row >= max_r || col < 0 || col >= max_r) return true;

        if (grid[row][col] == '1' && ma[row][col]) return false; // 如果该岛屿已经探索过了 返回 false

        if (grid[row][col] == '1' && !ma[row][col]) { // 如果当前是岛屿而且没有探索过
            ma[row][col] = true;

            // 在遍历的过程中发现会走回头路 设置四个方位标记

            if (st == "00") { // 表示不能往下走
                cout << "up" << endl;
                return dfs(grid, ma, row - 1, col, max_r, max_c, "00") // 往上走
                    && dfs(grid, ma, row, col - 1, max_r, max_c, "10") // 往左走
                    && dfs(grid, ma, row, col + 1, max_r, max_c, "11"); // 往右走
            } else if (st == "01") { // 表示不能往上走
                cout << "down" << endl;
                return dfs(grid, ma, row + 1, col, max_r, max_c, "01") // 往下走
                    && dfs(grid, ma, row, col - 1, max_r, max_c, "10") // 往左走
                    && dfs(grid, ma, row, col + 1, max_r, max_c, "11"); // 往右走
            } else if (st == "10") { // 表示不能往右走
                cout << "left" << endl;
                return dfs(grid, ma, row + 1, col, max_r, max_c, "01") // 往下走
                    && dfs(grid, ma, row - 1, col, max_r, max_c, "00") // 往上走
                    && dfs(grid, ma, row, col - 1, max_r, max_c, "10"); // 往左走
            } else if (st == "11") { // 表示不能往左走
                cout << "right" << endl;
                return dfs(grid, ma, row - 1, col, max_r, max_c, "00") // 往上走
                    && dfs(grid, ma, row + 1, col, max_r, max_c, "01") // 往下走
                    && dfs(grid, ma, row, col + 1, max_r, max_c, "11"); // 往右走
            } else { // 否则就是都能走
                cout << "all --- " << " " << "row: " << row << " " << "col:" << col << endl;

                return dfs(grid, ma, row - 1, col, max_r, max_c, "00") // 往上走
                    && dfs(grid, ma, row + 1, col, max_r, max_c, "01") // 往下走
                    && dfs(grid, ma, row, col - 1, max_r, max_c, "10") // 往左走
                    && dfs(grid, ma, row, col + 1, max_r, max_c, "11"); // 往右走
            }
        }
        
        return true;
    }

    int numIslands(vector<vector<char> >& grid) {
        // write code here
        vector<vector<bool>> ma (200, vector<bool> (200, false)); // 无法在 private 中定义？
        
        for (int i = 0; i < grid.size(); i ++) {
            for (int j = 0; j < grid[0].size(); j ++) {
                if (grid[i][j] == '1') {
                    res += dfs(grid, ma, i, j, grid.size(), grid[0].size(), "aaa") ? 1 : 0;

                    cout << "res: " << res  << " i: " << i << " j: " << j << endl;

                    //cout << "idx: " << dfs(grid, ma, i, j, grid.size(), grid[0].size(), "aaa") << endl;
                }
            }
        }
        return res;
    }

private:
    int res = 0; */

    void dfs (int row, int col, vector<vector<char>>& grid) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == '0') return;

        grid[row][col] = '0';

        dfs(row - 1, col, grid);
        dfs(row + 1, col, grid);
        dfs(row, col - 1, grid);
        dfs(row, col + 1, grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;

        for (int i = 0; i < grid.size(); i ++) for (int j = 0; j < grid[0].size(); j ++) if (grid[i][j] == '1') res ++, dfs(i, j, grid);
                
        return res;
    }
};
// @lc code=end

