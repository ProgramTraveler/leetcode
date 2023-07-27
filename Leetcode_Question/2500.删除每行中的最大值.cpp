class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        for (auto &g : grid) sort(g.begin(), g.end());

        int res = 0;
        
        int r = grid.size(), c = grid[0].size();

        for (int i = 0; i < c; i ++) {
            int tem = 0;
            for (int j = 0; j < r; j ++) {
                tem = max(tem, grid[j][i]);
            }

            res += tem;
        }

        return res;
    }
};