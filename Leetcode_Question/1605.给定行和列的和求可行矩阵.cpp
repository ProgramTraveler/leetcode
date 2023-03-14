/*
 * @lc app=leetcode.cn id=1605 lang=cpp
 *
 * [1605] 给定行和列的和求可行矩阵
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size(), n = colSum.size();

        vector<vector<int>> res(m, vector<int>(n)); // m 行 n 列的数组

        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                res[i][j] = min(rowSum[i], colSum[j]);

                rowSum[i] -= res[i][j];
                colSum[j] -= res[i][j];
            }
        }

        return res;
    }
};
// @lc code=end

