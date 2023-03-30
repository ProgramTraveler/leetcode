/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 */

// @lc code=start
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // 腐烂的橘子不止一个？
        // 广度搜索
        queue<pair<int, int>> qu;

        int res = 0;

        int row = grid.size(), col = grid[0].size();

        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (int i = 0; i < row; i ++) {
            for (int j = 0; j < col; j ++) {
                if (grid[i][j] == 2) qu.emplace(i, j);
            }
        }

        bool idx = false;

        while (!qu.empty()) {
            queue<pair<int, int>> tem;

            idx = false;

            while (!qu.empty()) {
                tem.emplace(qu.front());

                qu.pop();
            }

            while (!tem.empty()) {
                auto [i, j] = tem.front();

                tem.pop();

                for (int d = 0; d < 4; d ++) { // 向四个方向遍历
                    int ni = dirs[d][0] + i, nj = dirs[d][1] + j;

                    if (ni >= 0 && ni < row && nj >= 0 && nj < col && grid[ni][nj] == 1) { // 新鲜的橘子
                        grid[ni][nj] = 2;

                        qu.emplace(ni, nj);

                        idx = true; // 腐坏的标志
                    }
                }
            }

            if (idx) res ++;
        }

        for (int i = 0; i < row; i ++) {
            for (int j = 0; j < col; j ++) {
                if (grid[i][j] == 1) {
                    res = -1;

                    break;
                }
            }
        }

        return res;

    }
};
// @lc code=end

