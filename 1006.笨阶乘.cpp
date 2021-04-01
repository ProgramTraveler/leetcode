/*
 * @lc app=leetcode.cn id=1006 lang=cpp
 *
 * [1006] 笨阶乘
 */

// @lc code=start
class Solution {
public:
    int clumsy(int N) {
        stack<int> ans;
        int op = 0;
        ans.push(N);
        for (int i = N - 1; i > 0; i --) {
            if (op == 0) {
                int temp = ans.top();
                ans.pop();
                ans.push(temp * i);
            } else if (op == 1) {
                int temp = ans.top();
                ans.pop();
                ans.push(temp / i);
            } else if (op == 2) {
                ans.push(i);
            } else if (op == 3) {
                ans.push(-i);
            }
            op = (op + 1) % 4;
        }
        int res = 0;
        while (!ans.empty()) {
            res += ans.top();
            ans.pop();
        }
        return res;
    }
};
// @lc code=end

