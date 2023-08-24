/*
 * @lc app=leetcode.cn id=1267 lang=cpp
 *
 * [1267] 统计参与通信的服务器
 */

// @lc code=start
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int res = 0;

        int row = grid.size(), col = grid[0].size();

        // 栈溢出 应该是无限循环了
        // function<void(int, int)> dfs = [&](int i, int j) {
        //     // cout << ((i >= row || i < 0) || (j < 0 || j >= col)) << endl;
        //     if ((i >= row || i < 0) || (j < 0 || j >= col)) return; // 如果超过边界

        //     if (grid[i][j] == 2 || grid[i][j] == -1) return; // 已经标记

        //     if (grid[i][j] == 0) grid[i][j] = -1; // 

        //     // 向上下左右搜索
        //     if (grid[i][j] == 1) { // 如果是电脑
        //         grid[i][j] = 2; // 标记

        //         int cnt = 0;

        //         if ((i - 1) >= 0 && grid[i - 1][j] > 0) cnt ++;

        //         if ((i + 1) < row && grid[i + 1][j] > 0) cnt ++;

        //         if ((j - 1) >= 0 && grid[i][j - 1] > 0) cnt ++;

        //         if ((j + 1) < col && grid[i][j + 1] > 0) cnt ++;

        //         // cout << cnt << endl;

        //         res += cnt > 0 ? 1 : 0;
        //     }

        //     dfs(i - 1, j); // 上
        //     dfs(i + 1, j); // 下
        //     dfs(i, j - 1); // 左
        //     dfs(i, j + 1); // 右
        // };

        // dfs(0, 0);

        // 题目没审好
        // 同一行或者同一列 没必要是相邻的

        unordered_map<int, int> al_r;
        unordered_map<int, int> al_c;

        for (int i = 0; i < row; i ++) {
            for (int j = 0; j < col; j ++) {
                if (grid[i][j] == 1) {
                    al_r[i] ++;
                    al_c[j] ++;
                }
            }
        }

        for (int i = 0; i < row; i ++) {
            for (int j = 0; j < col; j ++) {
                if (grid[i][j] == 1 && (al_r[i] >= 2 || al_c[j] >= 2)) res ++;
            }
        }

        return res;
    }
};
// @lc code=end

