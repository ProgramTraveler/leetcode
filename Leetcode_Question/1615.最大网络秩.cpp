/*
 * @lc app=leetcode.cn id=1615 lang=cpp
 *
 * [1615] 最大网络秩
 */

// @lc code=start
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        // 貌似是第一次遇到对图的题目
        // 图的题目还是不怎么会写
        // 这个题还是挺简单的
        vector<vector<bool>> con(n, vector<bool>(n, false));
        vector<int> degree(n, 0);

        for (auto v : roads) {
            con[v[0]][v[1]] = true, con[v[1]][v[0]] = true;

            degree[v[0]] ++, degree[v[1]] ++;
        }

        int maxRank = 0;

        for (int i = 0; i < n; i ++) {
            for (int j = i + 1; j < n; j ++) { // j = i + 1
            
                int rank = degree[i] + degree[j] - (con[i][j] ? 1 : 0);

                maxRank = max(maxRank, rank);
            }
        }

        return maxRank;
    }
};
// @lc code=end

