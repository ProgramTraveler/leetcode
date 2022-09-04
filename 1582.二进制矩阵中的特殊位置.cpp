/*
 * @lc app=leetcode.cn id=1582 lang=cpp
 *
 * [1582] 二进制矩阵中的特殊位置
 */

// @lc code=start
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        int res = 0;

        vector<int> rowsSum(m); //统计每行的和
        vector<int> colsSum(n); //统计每列的和

        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                rowsSum[i] += mat[i][j];
                colsSum[j] += mat[i][j];
            }
        }

        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (mat[i][j] == 1 && rowsSum[i] == 1 && colsSum[j] == 1) res ++;
            }
        }

        return res;
    }
};
// @lc code=end

