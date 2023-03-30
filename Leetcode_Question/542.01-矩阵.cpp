/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 */

// @lc code=start
class Solution {
private:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dist(m, vector<int>(n));
        vector<vector<int>> seen(m, vector<int>(n));
        queue<pair<int, int>> q;
        // 将所有的 0 添加进初始队列中
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    q.emplace(i, j);
                    seen[i][j] = 1;
                }
            }
        }

        // 广度优先搜索
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (int d = 0; d < 4; ++d) {
                int ni = i + dirs[d][0];
                int nj = j + dirs[d][1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && !seen[ni][nj]) {
                    dist[ni][nj] = dist[i][j] + 1;
                    q.emplace(ni, nj);
                    seen[ni][nj] = 1;
                }
            }
        }

        return dist;
    }
};
/*class Solution {
public:

    int min_fun(int i, int j, int x, int y) {
        int idx_1 = min(i, j);
        int idx_2 = min(x, y);

        return min(idx_1, idx_2);
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int row = mat.size(), col = mat[0].size();
        
        function<int(int, int, int)> dfs = [&](int i, int j, int res) -> int {
            if (i < 0 || j < 0 || i >= row || j >= col) {
                return INT_MAX;
            }

            if (mat[i][j] == 0) return res;

            if (mat[i][j] != 0) {
                res ++;
                int tem_1 = dfs(i + 1, j, res);
                int tem_2 = dfs(i - 1, j, res);
                int tem_3 = dfs(i, j + 1, res);
                int tem_4 = dfs(i, j - 1, res);

                res =  min_fun(tem_1, tem_2, tem_3, tem_4);

                return res;
            }

            return res;
        };

        for (int i = 0; i < row; i ++) {
            for (int j = 0; j < col; j ++) {
                if (mat[i][j] != 0) {
                    mat[i][j] = dfs(i ,j, 0);
                }
            }
        }

        return mat;
    }
};*/
// @lc code=end

