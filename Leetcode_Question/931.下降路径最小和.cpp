/*
 * @lc app=leetcode.cn id=931 lang=cpp
 *
 * [931] 下降路径最小和
 */

// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n));
        copy(matrix[0].begin(), matrix[0].end(), dp[0].begin());
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int mn = dp[i - 1][j];
                if (j > 0) {
                    mn = min(mn, dp[i - 1][j - 1]);
                }
                if (j < n - 1) {
                    mn = min(mn, dp[i - 1][j + 1]);
                }
                dp[i][j] = mn + matrix[i][j];
            }
        }
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());


        /* 超时
        // dfs

        int res = INT_MAX;

        int row = matrix.size();
        int col = matrix[0].size();

        int sum = 0;

        function<void(int, int)> dfs = [&](int i, int j) {
            if (i >= row) {
                res = min(res, sum);

                return;
            }

            if (j < 0 || j >= col) return;

            sum += matrix[i][j];

            dfs(i + 1, j);
            dfs(i + 1, j + 1);
            dfs(i + 1, j - 1);

            sum -= matrix[i][j];
        };

        for (int i = 0; i < col; i ++) {
            dfs(0, i);
        }

        return res;*/
    }
};;
// @lc code=end

