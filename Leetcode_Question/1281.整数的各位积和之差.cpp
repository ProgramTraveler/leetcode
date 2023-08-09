/*
 * @lc app=leetcode.cn id=1281 lang=cpp
 *
 * [1281] 整数的各位积和之差
 */

// @lc code=start
class Solution {
public:
    int subtractProductAndSum(int n) {
        long long n1 = 1, n2 = 0;

        while (n > 0) {
            n1 *= (n % 10);
            n2 += n % 10;

            n /= 10;
        }

        return n1 - n2;
    }
};
// @lc code=end

