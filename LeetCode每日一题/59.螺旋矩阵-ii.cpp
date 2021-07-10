/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector(n, 0));
        int index = 1, left = 0, up = 0, right = n - 1, down = n - 1;
        while (index <= n * n) {
            for (int i = left; i <= right; i ++) ans[up][i] = index ++;
            up ++;
            for (int i = up; i <= down; i ++) ans[i][right] = index ++;
            right --;
            for (int i = right; i >= left; i --) ans[down][i] = index ++;
            down --;
            for (int i = down; i >= up; i --) ans[i][left] = index ++;
            left ++;
        }
        return ans;
    }
};
// @lc code=end

