/*
 * @lc app=leetcode.cn id=1678 lang=cpp
 *
 * [1678] 设计 Goal 解析器
 */

// @lc code=start
class Solution {
public:
    string interpret(string command) {
        string res = "";

        int idx = 0;

        while (idx < command.size()) {
            if (command[idx] == 'G') res += "G", idx ++;

            if (command[idx] == '/') idx ++;

            if (command[idx] == '(' && command[idx + 1] == ')') res += "o", idx += 2;

            if (command[idx] == '(' && command[idx + 1] == 'a') res += "al", idx += 4; 
        }

        return res;
    }
};
// @lc code=end

