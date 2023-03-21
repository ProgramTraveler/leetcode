/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */

// @lc code=start
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // key 对应 val
        // val 也对应 key

        unordered_map<char, string> al;
        unordered_map<string, char> idx;
        
        vector<string> cnt;

        string tem = "";
        for (int i = 0; i < s.size(); i ++) {
            if (s[i] != ' ') tem.push_back(s[i]);

            else cnt.push_back(tem), tem.clear(); 
        }

        cnt.push_back(tem);

        if (cnt.size() != pattern.size()) return false;


        for (int i = 0; i < cnt.size(); i ++) {
            if (al.find(pattern[i]) != al.end() && al[pattern[i]] != cnt[i]) return false;

            if (idx.find(cnt[i]) != idx.end() && idx[cnt[i]] != pattern[i]) return false;
            
            al[pattern[i]] = cnt[i];
            idx[cnt[i]] = pattern[i];
        }

        return true;
    }
};
// @lc code=end

