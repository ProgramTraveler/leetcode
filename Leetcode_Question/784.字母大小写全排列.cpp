/*
 * @lc app=leetcode.cn id=784 lang=cpp
 *
 * [784] 字母大小写全排列
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        // 大小写转变
        // 数字保持不变
        vector<string> res;
        int n = s.size();

        function<void(int)> dfs = [&](int i) {
            while (i < n && isdigit(s[i])) i ++; // 跳过数字位
            
            if (i == n) {
                res.push_back(s);

                return ;
            }
            
            // s[i] ^= 32;
            s[i] = toupper(s[i]);
            dfs (i + 1);

            // s[i] ^= 32;
            s[i] = tolower(s[i]);
            dfs(i + 1);
        };

        dfs(0);

        return res;
    }
};
// @lc code=end

