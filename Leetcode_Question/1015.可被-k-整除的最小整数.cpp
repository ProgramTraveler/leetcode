/*
 * @lc app=leetcode.cn id=1015 lang=cpp
 *
 * [1015] 可被 K 整除的最小整数
 */

// @lc code=start
class Solution {
public:
    int smallestRepunitDivByK(int k) {
        unordered_set<int> seen;

        int x = 1 % k;

        while (x && !seen.count(x)) {
            seen.insert(x);

            x = (x * 10 + 1) % k;
        }
        
        return x ? -1 : seen.size() + 1;
    }
};
// @lc code=end

