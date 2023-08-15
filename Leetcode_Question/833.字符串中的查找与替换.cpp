/*
 * @lc app=leetcode.cn id=833 lang=cpp
 *
 * [833] 字符串中的查找与替换
 */

// @lc code=start
class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int n = s.length();

        vector<pair<string, int>> replace(n, {"", 1}); // 无须替换时 i += 1

        for (int i = 0; i < indices.size(); i ++) {
            if (s.compare(indices[i], sources[i].length(), sources[i]) == 0) {
                replace[indices[i]] = {targets[i], sources[i].length()}; // {替换后的字符串，被替换的长度}
            }
        }

        string res;

        for (int i = 0; i < n; i += replace[i].second) { // 无需替换时 i += 1
            if (replace[i].first.empty()) {
                res += s[i];
            } else {
                res += replace[i].first;
            }
        }

        return res;
    }
};
// @lc code=end

