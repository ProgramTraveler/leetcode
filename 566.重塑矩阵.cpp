/*
 * @lc app=leetcode.cn id=566 lang=cpp
 *
 * [566] 重塑矩阵
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int row = nums.size(); //行数
        int col = nums[0].size(); //列数
        //如果当前矩阵的个数不能维持下一个矩阵，直接返回原来的矩阵
        if (row * col != r * c)
            return nums;
        //记录新的矩阵
        vector<vector<int>> ans(r, vector<int>(c, 0));
        int ROW = 0, COL = 0; // 维持新矩阵的行数和列数
        //对nums数组进行遍历
        for (int i = 0; i < row; i ++) {
            for (int j = 0; j < col; j ++) {
                //如果列数到达了当前的最后一列，转到下一行
                if (COL == c) {
                    ROW += 1;
                    COL = 0;
                }
                //记录矩阵中的数字
                ans[ROW][COL] = nums[i][j];
                COL += 1;
            }
        }
        //返回结果
        return ans;
    }
};
// @lc code=end

