/*
 * @lc app=leetcode.cn id=1784 lang=cpp
 *
 * [1784] 检查二进制字符串字段
 */

// @lc code=start
class Solution {
public:
    bool checkOnesSegment(string s) {
        /*
        对 find() 函数的一些解释 如果查找失败返回就是 string :: npos 也就是-1 但打印的结果并不是 -1
        */
        return s.find("01") == string :: npos; // mad 傻鸟语文出题组
    }
};
// @lc code=end

