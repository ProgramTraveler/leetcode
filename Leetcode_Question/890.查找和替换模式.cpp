/*
 * @lc app=leetcode.cn id=890 lang=cpp
 *
 * [890] 查找和替换模式
 */

// @lc code=start
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        /*
            构造双哈希表
        */

        vector<string> res;

        for (auto& word : words) {
            unordered_map<char, char> w;
            unordered_map<char, char> p;
            bool flag = true;

            for (int i = 0; i < pattern.size(); i ++) {
                if ((w.count(word[i]) && w[word[i]] != pattern[i]) || (p.count(pattern[i]) && p[pattern[i]] != word[i])) {
                    flag = false;
                    break;
                }

                w[word[i]] = pattern[i];
                p[pattern[i]] = word[i];

            }

            if (flag) res.push_back(word);
        }
        return res;
    }
};
// @lc code=end

