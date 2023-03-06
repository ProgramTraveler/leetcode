/*
 * @lc app=leetcode.cn id=1653 lang=cpp
 *
 * [1653] 使字符串平衡的最少删除次数
 */

// @lc code=start
class Solution {
public:
    int minimumDeletions(string s) { // 这个思路很不错 
        int del = 0;

        for (char c : s) del += 'b' - c; // 统计 a 的个数

        int res = del;

        for (char c : s) del += (c - 'a') * 2 - 1, res = min(del, res);
        
        return res;
    }
};
// @lc code=end

