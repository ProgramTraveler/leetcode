/*
 * @lc app=leetcode.cn id=1807 lang=cpp
 *
 * [1807] 替换字符串中的括号内容
 */

// @lc code=start
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string res = "";

        string tem_s = "";
        bool idx = false; // false 表示没有遇到括号

        unordered_map<string, string> ma1; // 记录数组中的键值对
        unordered_map<string, int> ma2; // 记录键值对是否存在

        for (int i = 0; i < knowledge.size(); i ++) ma1[knowledge[i][0]] = knowledge[i][1], ma2[knowledge[i][0]] = 1;
        

        for (auto c : s) {
            if (idx && c != '(' && c != ')') tem_s += c; // 如果是在括号中的字符串 先存在临时字符串中

            if (!idx && c != '(' && c != ')') res += c; // 只是字符就存在最终结果中

            if (c == '(') idx = true;

            if (c == ')') {
                idx = false;

                if (ma2[tem_s]) res += ma1[tem_s];

                else res += '?';

                tem_s = ""; // 将临时字符串初始化
            }
        }

        return res;
    } 
};
// @lc code=end

