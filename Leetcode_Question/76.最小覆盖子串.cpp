/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    unordered_map<char, int> ori, cnt;

    bool check() {
        for (const auto &p : ori) {
            if (cnt[p.first] < p.second) return false;
        }

        return true;
    } 

    string minWindow(string s, string t) {

        if (s.size() < t.size()) return "";

        for (const auto &c : t) ori[c] ++;

        int l = 0, r = - 1;

        int len = INT_MAX, ansl = -1;

        while (r < int(s.size())) {
            if (ori.find(s[++ r]) != ori.end()) cnt[s[r]] ++;

            while (check() && l <= r) {
                if (r - l + 1 < len) {
                    len = r - l + 1;
                    ansl = l;
                }

                if (ori.find(s[l]) != ori.end()) {
                    cnt[s[l]] --;
                }

                ++ l;
            }
        }

        return ansl == -1 ? string() : s.substr(ansl, len);
    }
};
// @lc code=end

