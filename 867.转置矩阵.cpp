/*
 * @lc app=leetcode.cn id=867 lang=cpp
 *
 * [867] 转置矩阵
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> ans(matrix[0].size(),vector<int>(matrix.size()));
        int left = 0, right = 0;
        for (int i = 0; i < matrix.size(); i ++) {
            for (int j = 0; j < matrix[i].size(); j ++) {                
                ans[j][i] = matrix[i][j];
            }
        }
        return ans;
    }
};
// @lc code=end

