/*
 * @lc app=leetcode.cn id=598 lang=cpp
 *
 * [598] 范围求和 II
 */

// @lc code=start
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        // 正常思想 -> 三层循环 -> 超出内存限制
        /*if (ops.size() == 0) return m * n;

        vector<vector<int>> M(m, vector(n, 0));


        int res = 0;
        unordered_map<int, int> al;

        for (int i = 0; i < ops.size(); i ++) {
            int row = ops[i][0], col = ops[i][1];

            for (int i = 0; i < row; i ++) for (int j = 0; j < col; j ++) M[i][j] ++, res = max(M[i][j], res);
        }

        for (int i = 0; i < m; i ++) for (int j = 0; j < n; j ++) al[M[i][j]] ++;

        return al[res];*/
        /*
        由于每次都是对 0 ≤ i < a 和 0 ≤ j < b 进行操作
        因此每次操作都会包含点 (0,0) -> 最后的最大值一定出现在位置 (0,0) 上

        问题转换为 -> 什么范围内的数与位置 (0,0) 上的值相等 -> 即什么范围会被每一次操作所覆盖
         -> 在所有的 ops[i] 中的横纵坐标 (x,y) 与左上角 (0,0) 形成的区域面积可确保被每次操作覆盖 x∗y 即是答案
        */
        int row = m, col = n;

        for (auto &op : ops) {
            row = min(row, op[0]);
            col = min(col, op[1]);
        }

        return row * col;
    }
};
// @lc code=end

