/*
 * @lc app=leetcode.cn id=766 lang=cpp
 *
 * [766] 托普利茨矩阵
 */

// @lc code=start
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        //对矩阵中的元素进行遍历，只要当前数和它右下角元素相同说明满足条件
        for (int i = 0; i < matrix.size() - 1; i ++) { //最后一行和最后一列不用考虑
            for (int j = 0;j < matrix[0].size() - 1; j ++)
                //不等就返回false
                if (matrix[i][j] != matrix[i + 1][j + 1])
                    return false;
        }
        return true;
    }
};
// @lc code=end

