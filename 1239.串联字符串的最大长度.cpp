/*
 * @lc app=leetcode.cn id=1239 lang=cpp
 *
 * [1239] 串联字符串的最大长度
 */

// @lc code=start
class Solution {
public:
    int maxLength(vector<string> &arr) {
        vector<int> masks;
        for (string &s : arr) {
            int mask = 0;
            for (char ch : s) {
                ch -= 'a';
                if ((mask >> ch) & 1) { // 若 mask 已有 ch，则说明 s 含有重复字母，无法构成可行解
                    mask = 0;
                    break;
                }
                mask |= 1 << ch; // 将 ch 加入 mask 中
            }
            if (mask > 0) {
                masks.push_back(mask);
            }
        }

        int ans = 0;
        function<void(int, int)> backtrack = [&](int pos, int mask) {
            if (pos == masks.size()) {
                ans = max(ans, __builtin_popcount(mask));
                return;
            }
            if ((mask & masks[pos]) == 0) { // mask 和 masks[pos] 无公共元素
                backtrack(pos + 1, mask | masks[pos]);
            }
            backtrack(pos + 1, mask);
        };
        backtrack(0, 0);
        return ans;
    }
};
// @lc code=end

