class Solution {
public:
    int fun (vector<vector<int>>& grid, int row, int col) {
        int tem = INT_MIN;

        for (int k = row, idx_r = 1; idx_r <= 3; k ++, idx_r ++) {
            for (int c = col, idx_c = 1; idx_c <= 3; c ++, idx_c ++) {
                tem = max(tem, grid[k][c]);
            }
        }

        return tem;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {

        int n = grid[0].size();

        vector<vector<int>> res(n - 2, vector<int>(n - 2, 0));

        for (int i = 0; i < n - 2; i ++) {
            for (int j = 0; j < n -2; j ++) {
                res[i][j] = fun(grid, i, j);
            }
        }

        return res;
    }
};