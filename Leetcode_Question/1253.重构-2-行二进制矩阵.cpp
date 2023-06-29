/*
 * @lc app=leetcode.cn id=1253 lang=cpp
 *
 * [1253] 重构 2 行二进制矩阵
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        vector<vector<int>> res;
        // vector<vector<int>> tem;

        int cols = accumulate(colsum.begin(), colsum.end(), 0);
        int n = colsum.size();

        if (upper + lower != cols || upper > n || lower > n) return {};

        // 和为 2 的时候不用考虑 二者皆出
        // 唯一是考虑为 1 的时候 关键是 谁出？
        res.resize(2, vector(n, 0));
        int idx = 0;

        // 谁多谁出
        for (int i = 0; i < n && (upper >= 0 && lower >= 0); i ++) {
            idx = i;
            if (colsum[i] == 1) {
                if (upper >= lower) res[0][i] = 1, upper --;

                else res[1][i] = 1, lower --;
            }

            if (colsum[i] == 2) res[0][i] = 1, res[1][i] = 1, upper --, lower --;
        }

        if (idx + 1 != n) return {};

        return res;
    }
};
// @lc code=end

