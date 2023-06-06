/*
 * @lc app=leetcode.cn id=2352 lang=cpp
 *
 * [2352] 相等行列对
 */

// @lc code=start
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        // 还能以数组做 key 学到了
        // 似乎 unordered_map 不能这样用
        map<vector<int>, int> cnt;

        int res = 0;

        int n = grid.size();

        for (auto arr : grid) cnt[arr] ++;

        for (int j = 0; j < n; j ++) {
            vector<int> arr;

            for (int i = 0; i < n; i ++) {
                arr.emplace_back(grid[i][j]);
            }

            if (cnt.find(arr) != cnt.end()) res += cnt[arr];
        }

        return res;
    }
};
// @lc code=end

