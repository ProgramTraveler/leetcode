/*
 * @lc app=leetcode.cn id=2981 lang=cpp
 *
 * [2981] 找出出现至少三次的最长特殊子字符串 I
 */

// @lc code=start
class Solution {
public:
    int maximumLength(string s) {
        std::vector<int> groups[26];
        int cnt = 0, n = s.size();
        for (int i = 0; i < n; i ++) {
            cnt ++;
            if (i + 1 == n || s.at(i) != s.at(i + 1)) {
                groups[s.at(i) - 'a'].push_back(cnt);
                cnt = 0;
            }
        }

        int res = 0;
        for (auto& a : groups) {
            if (a.empty()) {
                continue;
            }
            ranges::sort(a, greater());
            a.push_back(0);
            a.push_back(0);
            res = max({res, a[0] - 2, min(a[0] - 1, a[1]), a[2]});
        }

        return res ? res : -1;
    }
};
// @lc code=end

