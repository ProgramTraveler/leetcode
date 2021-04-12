/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n + 1);
        int p1 = 1, p2 = 1, p3 = 1;
        dp[1] = 1; //第一个丑数是1
        for (int i = 2; i <= n; i ++) {
            int num1 = dp[p1] * 2, num2 = dp[p2] * 3, num3 = dp[p3] * 5;
            dp[i] = min(min(num1, num2), num3); //取三个数中的最小的数为新的丑数
            if (dp[i] == num1)
                p1 ++;
            if (dp[i] == num2)
                p2 ++;
            if (dp[i] == num3)
                p3 ++;
        }
        return dp[n];
    }
};
// @lc code=end

