/*
 * @lc app=leetcode.cn id=1572 lang=cpp
 *
 * [1572] 矩阵对角线元素的和
 */

// @lc code=start
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size();
        vector<vector<bool>> idx(row, vector<bool>(col, false)); // 是否扫过

        int res = 0;

        // 遍历主对角线
        int r = 0, c = 0;
        while (r < row && c < col) {
            if (idx[r][c] == false) res += mat[r][c], idx[r][c] = true;
            r ++, c ++;
        }

        r = 0, c = col - 1;

        while (r < row && c >= 0) {
            if (idx[r][c] == false) res += mat[r][c], idx[r][c] = true;

            r ++, c --;
        }

        return res;
    }
};
// @lc code=end

