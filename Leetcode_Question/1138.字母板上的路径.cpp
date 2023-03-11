/*
 * @lc app=leetcode.cn id=1138 lang=cpp
 *
 * [1138] 字母板上的路径
 */

// @lc code=start
class Solution {
public:
    string alphabetBoardPath(string target) {
        string res = "";

        int cx = 0, cy = 0;

        for (auto c : target) {
            // 字母板有 5 行 5 列 字母 Z 进行特殊考虑
            int nx = (c - 'a') / 5;
            int ny = (c - 'a') % 5;

            if (nx < cx) res.append(cx - nx, 'U');

            if (ny < cy) res.append(cy - ny, 'L');

            if (nx > cx) res.append(nx - cx, 'D');

            if (ny > cy) res.append(ny - cy, 'R');

            res.push_back('!');

            // 更新坐标

            cx = nx, cy = ny;
        }

        return res;
    }
};
// @lc code=end

