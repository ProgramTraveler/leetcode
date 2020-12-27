/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> map1;
        unordered_map<char, char> map2;
        for (int i = 0, j = 0; i < s.size(); i++, j++) {
            if (map1.find(s[i]) == map1.end()) { // map1保存s[i] 到 t[j]的映射
                map1[s[i]] = t[j];
            }
            if (map2.find(t[j]) == map2.end()) { // map2保存t[j] 到 s[i]的映射
                map2[t[j]] = s[i];
            }
            // 发现映射 对应不上，立刻返回false
            if (map1[s[i]] != t[j] || map2[t[j]] != s[i]) {
                return false;
            }
        }
        return true;
    }
};

// @lc code=end

