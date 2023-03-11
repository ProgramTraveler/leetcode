/*
 * @lc app=leetcode.cn id=2042 lang=cpp
 *
 * [2042] 检查句子中的数字是否递增
 */

// @lc code=start
class Solution {
public:
    bool areNumbersAscending(string s) {
        vector<int> res;

        int idx = -1;

        for (int i = 0; i < s.size(); i ++) {
            if (isdigit(s[i])) {

                if ((i - 1 >= 0) && isdigit(s[i - 1])) res[idx] = res[idx] * 10 + (s[i] - '0');
                
                else idx ++, res.push_back(s[i] - '0');
            }
        }

        for (int i = 1; i < res.size(); i ++) if (res[i] <= res[i - 1]) return false;

        return true;
    }
};
// @lc code=end

