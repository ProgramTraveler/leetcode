/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // s 和 p 仅包含小写字母
        int l = 0, r = 0;

        int n1 = s.size();
        int n2 = p.size();

        if (n2 > n1) return {};

        vector<int> pcnt(26, 0);
        vector<int> scnt(26, 0);

        vector<int> res;

        for (int i = 0; i < n2; i ++) {
            scnt[s[i] - 'a'] ++;

            pcnt[p[i] - 'a'] ++;
        }

        if (scnt == pcnt) { // 如果两个数组中出现的个数都相等 是一个异位词
            res.emplace_back(0);
        }

        for (int i = 0; i < n1 - n2; i ++) {
            scnt[s[i] - 'a'] --;

            scnt[s[i + n2] - 'a'] ++;

            if (scnt == pcnt) res.emplace_back(i + 1); // 可以直接 == 数组？ 我一直在想怎么判断两个数组是否相等...
        }

        return res;

        /*
        超时了 能过所有的测试样例
        
        if (p.size() > s.size()) return {};

        vector<int> al(26, 0);

        vector<int> res;

        int l = 0, r = 0;

        while (l <= s.size() - p.size()) {

            fill(al.begin(), al.end(), 0);

            for (auto c : p) al[c - 'a'] ++;

            r = l;

            while (r < (l + p.size())) {
                if (al[s[r] - 'a'] > 0) al[s[r] - 'a'] --;

                else break;

                r ++;
            }

            if (accumulate(al.begin(), al.end(), 0) == 0) res.emplace_back(l);

            l ++;
        }

        return res;
        */
    }
};
// @lc code=end

