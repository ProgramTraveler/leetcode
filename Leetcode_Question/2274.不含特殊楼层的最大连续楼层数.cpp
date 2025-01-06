/*
 * @lc app=leetcode.cn id=2274 lang=cpp
 *
 * [2274] 不含特殊楼层的最大连续楼层数
 */

// @lc code=start
class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        std::sort(special.begin(), special.end());
        int res = 0;
        int tmp_bottom = bottom, tmp_top = top;
        int cnt = special.size() - 1;

        if (bottom < special[0]) {
            tmp_top = std::fmin(top, special[0] - 1);
            res = std::fmax(res, tmp_top - tmp_bottom + 1);
        }

        if (top > special[cnt]) {
            tmp_bottom = std::fmax(bottom, special[cnt] + 1);
            res = std::fmax(res, top - tmp_bottom + 1);
        }

        for (int i = 0; i < cnt; i ++) {
            int start = special[i] + 1;
            int end = special[i + 1] - 1;
            res = std::fmax(res, end - start + 1);
        }

        return res;
    }
};
// @lc code=end

