/*
 * @lc app=leetcode.cn id=1380 lang=cpp
 *
 * [1380] 矩阵中的幸运数
 */

// @lc code=start
class Solution {
    public List<Integer> luckyNumbers (int[][] matrix) {
        int m = matrix.length, n = matrix[0].length; //矩阵的行数和列数
        List<Integer> ans = new ArrayList<>();
        int[] row = new int[m]; //每行的最小值
        int[] col = new int[n]; //每列的最大值

        for (int i = 0; i < m; i ++) { //找出每行的最小值
            row[i] = matrix[i][0];
            for (int j = 0; j < n; j ++) {
                row[i] = Math.min(row[i], matrix[i][j]);
            }
        }

        for (int i = 0; i < n; i ++) { //找出每列的最大值
            col[i] = matrix[0][i];
            for (int j = 0; j < m; j ++) {
                col[i] = Math.max(col[i], matrix[j][i]);
            }
        }
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j  <n; j ++) {
                if (matrix[i][j] == row[i] && matrix[i][j] == col[j]) ans.add(matrix[i][j]);
            }
        }
        return ans;
    }
}
// @lc code=end

