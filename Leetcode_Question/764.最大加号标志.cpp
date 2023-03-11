/*
 * @lc app=leetcode.cn id=764 lang=cpp
 *
 * [764] 最大加号标志
 */

// @lc code=start
class Solution {
public:
    int DFS (int i, int j, vector<vector<int>>& t, int sq) {
        if ((i + sq) > t.size() - 1 || (j + sq) > t[0].size() - 1 || (i - sq) < 0 || (j - sq) < 0) return sq; // 如果碰到了边界 就直接返回结果
        
        if (t[i - sq][j] == 1 && t[i + sq][j] == 1 && t[i][j - sq] == 1 && t[i][j + sq] == 1) {
            sq += 1;
            
            sq = DFS(i, j, t, sq);

        }

        return sq;

    }
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> grid(n, vector<int>(n, 1));

        int res = 0; 

        for (int i = 0; i < mines.size(); i ++) grid[mines[i][0]][mines[i][1]] = 0;

        for (int i = 0; i < n; i ++) for (int j = 0; j < n; j ++) if (grid[i][j] != 0) res = max(res, DFS(i, j, grid, 1));     

        return res;
    }
};
// @lc code=end

