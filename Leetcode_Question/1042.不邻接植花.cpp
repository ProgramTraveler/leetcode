/*
 * @lc app=leetcode.cn id=1042 lang=cpp
 *
 * [1042] 不邻接植花
 */

// @lc code=start
class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        // 注意 路径是双向的
        // 保证答案是存在的

        vector<vector<int>> al(n); // 某个节点的的前置所有节点 最多只有三个

        for (int i = 0; i < paths.size(); i ++) {
            int f = paths[i][0] - 1, e = paths[i][1] - 1; // 保证下标从 0 开始

            al[f].push_back(e);
            al[e].push_back(f);
        }

        vector<int> res(n, 0); // 每个花园选择的花

        // 遍历节点 选择前置节点没有选择过的花
        // 感觉要 dfs
        for (int i = 0; i < n; i ++) {
            bool used[5] = {false};
            
            for (int j : al[i]) used[res[j]] = true; // 将前置的花园选择的花设为 true

            while (used[++ res[i]]); // 选择剩下的花朵
        }

        return res;

    }
};
// @lc code=end

