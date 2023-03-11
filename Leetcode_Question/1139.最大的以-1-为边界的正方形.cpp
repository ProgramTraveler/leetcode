/*
 * @lc app=leetcode.cn id=1139 lang=cpp
 *
 * [1139] 最大的以 1 为边界的正方形
 */

// @lc code=start
class Solution {
public:
    /*int DFS_1 (vector<vector<int>>& grid, int len, int s, int e) {
        if ((s + len) >= grid[0].size() || (e + len) >= grid.size()) { // 超过边界直接返回
            return len - 1;
        }

        if (grid[s][e + len] == 1 && grid[s + len][e] == 1) { // 如果边界是 1 继续扩展边
            
            len = DFS_1(grid, len + 1, s, e);
        
        }

        return len; // 返回最长边

    }

    int DFS_2 (vector<vector<int>>& grid, int len, int s, int e) {
        
        if ((s + len) >= grid[0].size() || (e + len) >= grid.size()) { // 超过边界直接返回
            return len + 1;
        }

        if (grid[s][e + len] == 1 && grid[s + len][e] == 1) {
            len = DFS_2(grid, len - 1, s, e);
        }

        return len;


    }

    int largest1BorderedSquare(vector<vector<int>>& grid) { // 关键是如何确定正方形
        int res = 0;

        int len_1 = 0, len_2 = 0;

        for (int i = 0; i < grid.size(); i ++) {

            for (int k = 0; k < grid[i].size(); k ++) {

                if (grid[i][k] == 1) {

                    len_1 = DFS_1(grid, 1, i, k); // 当前点可以扩展的最长边

                    int sta = i + len_1, end = k + len_1;

                    while (sta >= i && end >= k) {
                        if (grid[sta][end] == 1) len_2 = DFS_2(grid, -1, sta, end); // 可以满足条件的最短边 
                        if (len_2 >= len_1) res = max(res, len_1 * len_1);

                        else sta --, end --, len_1 --;
                    }

                }
            }
        }

        return res;

    }*/

    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> left(m + 1, vector<int>(n + 1));
        vector<vector<int>> up(m + 1, vector<int>(n + 1));
        int maxBorder = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (grid[i - 1][j - 1] == 1) {
                    left[i][j] = left[i][j - 1] + 1;
                    up[i][j] = up[i - 1][j] + 1;
                    int border = min(left[i][j], up[i][j]);
                    while (left[i - border + 1][j] < border || up[i][j - border + 1] < border) {
                        border--;
                    }
                    maxBorder = max(maxBorder, border);
                }
            }
        }
        return maxBorder * maxBorder;
    }
};
// @lc code=end

