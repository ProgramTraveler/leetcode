/*
 * @lc app=leetcode.cn id=1234 lang=cpp
 *
 * [1234] 替换子串得到平衡字符串
 */

// @lc code=start
class Solution {
public:
    int balancedString(string s) {
        int l = 0, res = INT_MAX;

        int n = s.size() / 4;

        unordered_map<char, int> al;

        for (char c : s) al[c] ++;

        if (al['Q'] == n && al['W'] == n && al['E'] == n && al['R'] == n) return 0;

        for (int r = 0; r < s.size(); r ++) {
            al[s[r]] --;

            while (al['Q'] <= n && al['W'] <= n && al['E'] <= n && al['R'] <= n) {
                res = min(res, r - l + 1);

                al[s[l]] ++, l ++;
            }
        }

        return res;
        

        /*int n = s.size() / 4, res = 0;

        unordered_map<char, int> al;

        for (char c : s) al[c] ++;

        for (auto [k, v] : al) {
            cout << k << " " << v << endl;

            if (v > n) res += (v - n);
        }

        return res;*/
    }
};
// @lc code=end

