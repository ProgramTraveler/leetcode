/*
 * @lc app=leetcode.cn id=791 lang=cpp
 *
 * [791] 自定义字符串排序
 */

// @lc code=start
class Solution {
public:
    string customSortString(string order, string s) {
        int al[26] = {0}, cnt = 1; // 26位字母表

        string res = "", res_tem = "";

        stack<char> in, out;

        for (auto c : order) al[c - 'a'] += cnt, cnt ++; // 生成字母的大小顺序序列

        for (auto c : s) {
            if (al[c - 'a'] == 0) res_tem += c;
            else {
                while (!in.empty()) {
                    if (al[c - 'a'] <= al[in.top() - 'a']) break;
                    else {
                        out.push(in.top()), in.pop();
                    }
                }
                in.push(c);

                while (!out.empty()) in.push(out.top()), out.pop();
            }
        }
        
        while (!in.empty()) res += in.top(), in.pop();

        res += res_tem;

        return res;
    }
};
// @lc code=end

