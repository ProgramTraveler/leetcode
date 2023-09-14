/*
 * @lc app=leetcode.cn id=1222 lang=cpp
 *
 * [1222] 可以攻击国王的皇后
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> res;

        vector<vector<bool>> mat(8, vector<bool>(8, false)); // 棋盘上某个位置是否存在 queen

        /*
            0 上
            1 下
            2 左
            3 右
            4 左上
            5 左下
            6 右上
            7 右下
        */
        vector<bool> idx(8, 1); // 8 个 方向是否遭到攻击 1 表示没有遭到攻击

        for (auto qu : queens) mat[qu[0]][qu[1]] = true;

        int s_i = king[0], s_j = king[1];

        // 先走十字
        for (int i = 0; i < 8; i ++) {
            if (idx[0] && (s_i - i) >= 0 && mat[s_i - i][s_j]) {
                res.push_back({s_i - i, s_j});

                idx[0] = 0;
            }

            if (idx[1] && (s_i + i) < 8 && mat[s_i + i][s_j]) {
                res.push_back({s_i + i, s_j});

                idx[1] = 0;
            }

            if (idx[2] && (s_j - i) >= 0 && mat[s_i][s_j - i]) {
                res.push_back({s_i, s_j - i});

                idx[2] = 0;
            }

            if (idx[3] && (s_j + i) < 8 && mat[s_i][s_j + i]) {
                res.push_back({s_i, s_j + i});

                idx[3] = 0;
            }
        }

        // 走斜
        for (int i = 0; i < 8; i ++) {
            if (idx[4] && (s_i - i) >= 0 && (s_j - i) >= 0 && mat[s_i - i][s_j - i]) {
                res.push_back({s_i - i, s_j - i});

                idx[4] = 0;
            }

            if (idx[5] && (s_i + i) < 8 && (s_j - i) >= 0 && mat[s_i + i][s_j - i]) {
                res.push_back({s_i + i, s_j - i});

                idx[5] = 0;
            }

            if (idx[6] && (s_i - i) >= 0 && (s_j + i) < 8 && mat[s_i - i][s_j + i]) {
                res.push_back({s_i - i, s_j + i});

                idx[6] = 0;
            }

            if (idx[7] && (s_i + i) < 8 && (s_j + i) < 8 && mat[s_i + i][s_j + i]) {
                res.push_back({s_i + i, s_j + i});

                idx[7] = 0;
            }
        }
        
        return res;
    }
};
// @lc code=end

