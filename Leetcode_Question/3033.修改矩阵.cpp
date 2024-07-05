/*
 * @lc app=leetcode.cn id=3033 lang=cpp
 *
 * [3033] 修改矩阵
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        std::vector<std::vector<int>> res; 
        std::vector<int> col_max; // 没列最大值
        for (int j = 0; j < matrix[0].size(); j ++) {
            int temp_col = INT_MIN;
            for (int i = 0; i < matrix.size(); i ++) {
                temp_col = std::fmax(temp_col, matrix[i][j]);
            }
            col_max.emplace_back(temp_col);
        }

        for (int i = 0; i < matrix.size(); i ++) {
            std::vector<int> temp_vec;
            for (int j = 0; j < matrix[0].size(); j ++) {
                if (matrix[i][j] == -1) {
                    temp_vec.emplace_back(col_max.at(j));
                } else {
                    temp_vec.emplace_back(matrix[i][j]);
                }
            }
            res.emplace_back(temp_vec);
        }

        return res;
    }
};
// @lc code=end

