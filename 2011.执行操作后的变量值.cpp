/*
 * @lc app=leetcode.cn id=2011 lang=cpp
 *
 * [2011] 执行操作后的变量值
 */

// @lc code=start
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int res = 0;

        for (int i = 0; i < operations.size(); i ++) {
            string tem = operations[i];

            res += tem[1] == '+' ? 1 : -1;
        }

        return res;
    }
};
// @lc code=end

