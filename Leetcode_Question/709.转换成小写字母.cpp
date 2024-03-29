/*
 * @lc app=leetcode.cn id=709 lang=cpp
 *
 * [709] 转换成小写字母
 */

// @lc code=start
class Solution {
public:
    string toLowerCase(string s) {
        //方法一，直接使用API，其实就是直接调库函数
        /*
        for (auto& ch : s) ch = tolower(ch);
        return s;
        */
        //方法二，手动实现API，感觉这才是这道题的意义，就是利用ASCLL
        for (auto& ch : s) {
            if (ch >= 65 && ch <= 90) //如果当前的字母是大写字母
                ch |= 32;
        }
        return s;
    }
};
// @lc code=end

