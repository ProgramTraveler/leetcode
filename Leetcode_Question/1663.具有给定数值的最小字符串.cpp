/*
 * @lc app=leetcode.cn id=1663 lang=cpp
 *
 * [1663] 具有给定数值的最小字符串
 */

// @lc code=start
class Solution {
public:
    string getSmallestString(int n, int k) {
        // 构造出长度为 n 且和为 k 的字符串
        // 还要字典序最小

        //官方给的是贪心 但是感觉贪心的思路不怎么好懂
        /*string res;

        for (int i = 1; i <= n; i ++) {
            int lower = max(1, k - (n - i) * 26);

            k -= lower;

            res.push_back('a' + lower - 1);
        }

        return res;*/

        // 还是这个思路好 首先都填入 a 然后再加

        string res (n, 'a'); // 这个初始化的方式 get

        int diff = k - n; // 剩下的数值 已经填入了 n 个 a

        int idx = n - 1; // 字符串下标

        while (diff > 25) {
            res[idx] = 'z';

            diff -= 25; // 因为将 a 换为了 z 所以 diff 应该是 + 1 - 26

            idx --;
        } 

        res[idx] = 'a' + diff;

        return res;
    }
};
// @lc code=end

