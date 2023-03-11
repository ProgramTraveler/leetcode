/*
 * @lc app=leetcode.cn id=526 lang=cpp
 *
 * [526] 优美的排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> match;
    vector<int> vis;
    int num;

    void backtrack(int index, int n) {
        if (index == n + 1) {
            num++;
            return;
        }
        for (auto &x : match[index]) {
            if (!vis[x]) {
                vis[x] = true;
                backtrack(index + 1, n);
                vis[x] = false;
            }
        }
    }

    int countArrangement(int n) {
        vis.resize(n + 1);
        match.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i % j == 0 || j % i == 0) {
                    match[i].push_back(j);
                }
            }
        }
        backtrack(1, n);
        return num;
    }
};
// @lc code=end

