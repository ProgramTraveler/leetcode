/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return;
        vector<vector<int>> newM(matrix); //创建一个新的数组
        int M = matrix.size(), N = matrix[0].size(); //原数组的行数和列数
        //对数组进行遍历
        for (int r = 0; r < M; ++r) {
            for (int c = 0; c < N; ++c) {
                if (newM[r][c] == 0) { //如果当前的数字是零
                    //将这一列变为0
                    for (int j = 0; j < N; ++j) {
                        matrix[r][j] = 0;
                    }
                    //将这一行变为0
                    for (int i = 0; i < M; ++i) {
                        matrix[i][c] = 0;
                    }
                }
            }
        }
    }
};
// @lc code=end

