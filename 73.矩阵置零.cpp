/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> row; //记录零出现的行号
        vector<int> col; //记录零出现的列号
        for (int i = 0; i < matrix.size(); i ++) {
            for (int j = 0; j < matrix[0].size(); j ++) {
                if (matrix[i][j] == 0) { //对零出现的位置进行记录
                    row.push_back(i); 
                    col.push_back(j);
                }
            }
        }
        //分别对零出现的行和列进行赋零操作
        for (int i = 0; i < row.size(); i ++) {
            for (int j = 0; j < matrix[0].size(); j ++) 
                matrix[row[i]][j] = 0;
        }
        for (int i = 0; i < col.size(); i ++) {
            for (int j = 0; j < matrix.size(); j ++) 
                matrix[j][col[i]] = 0;
        }
    }
};
// @lc code=end

