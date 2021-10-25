/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
/*class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0, cul = 0;
        for (int i = 0; i < matrix[0].size(); i ++) {
            if (matrix[0][i] > target && i >= 1) {
                cul = i - 1;
                break;
            }
        }
        for (int i = 0; i < matrix.size(); i ++) {
            if (matrix[i][cul] == target) return true;
        }
        return false;
    }

};*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (const auto& row: matrix) {
            auto it = lower_bound(row.begin(), row.end(), target);
            if (it != row.end() && *it == target) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

