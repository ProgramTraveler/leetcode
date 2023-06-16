/*
 * @lc app=leetcode.cn id=419 lang=cpp
 *
 * [419] 甲板上的战舰
 */

// @lc code=start
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        // 被题目描述日常迫害
        // 相连的战舰被看成是一个战舰
        int res = 0, row = board.size(), col = board[0].size();

        for (int i = 0; i < row; i ++) {
            for (int j = 0; j < col; j ++) if (board[i][j] == 'X' && (i == 0 || board[i - 1][j] =='.') && (j == 0 || board[i][j - 1] == '.')) res ++;
        }

        return res;
    }
};
// @lc code=end

