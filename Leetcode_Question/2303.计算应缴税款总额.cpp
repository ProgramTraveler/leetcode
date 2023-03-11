/*
 * @lc app=leetcode.cn id=2303 lang=cpp
 *
 * [2303] 计算应缴税款总额
 */

// @lc code=start
class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        /*double res = 0;

        int tem_inco = income; // 当前剩余的收入

        for (int i = 1; i < brackets.size(); i ++) brackets[i][0] = brackets[i][0] - brackets[i - 1][0];

        for (int i = 0; i < brackets.size(); i ++) {
            if (tem_inco == 0) break;

            int mon = min(brackets[i][0], tem_inco); // 当前需要缴纳的收入

            cout << mon << ' ' << tem_inco << ' ' << mon * brackets[i][1] * 0.01 << endl;

            res += mon * brackets[i][1] * 0.01;

            tem_inco -= min(brackets[i][0], tem_inco);
        }

        return res;*/

        double res = 0;

        int lower = 0;

        for (int i = 0; i < brackets.size(); i ++) {
            int upper = brackets[i][0], percent = brackets[i][1];

            int tax = (min(upper, income) - lower) * percent;

            res += tax;

            if (income <= upper) break;

            lower = upper;
        }

        return res / 100.0;
    }
};
// @lc code=end

