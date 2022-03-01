/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> rows(min(int(s.length()), numRows)); //记录字符串的数组
        int num = 0; //行号
        bool goDown = false; //判断是否往下一行移动
        for (char c : s) {//开始迭代s里的字符
            rows[num] += c; //把字符存入相应的行号
            if (num == 0 || num == numRows - 1) goDown =! goDown; //如果到了行头或者行尾就开始转行
            num += goDown ? 1 : -1; 
        }

        //开始从上往下遍历
        string r;
        for (string row : rows) r += row;
        return r;
    }
};
// @lc code=end

