/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // 这题没做过
        int n = nums.size();

        vector<vector<int>> res;

        vector<int> path(n), on_path(n);

        function<void(int)> dfs = [&](int i) {
            if (i == n) { // 全部放入
                res.push_back(path);
                return ;
            }

            for (int j = 0; j < n; j ++) { // 从头开始遍历
                if (!on_path[j]) { // 如果之前没有放
                    path[i] = nums[j]; // 放
                    on_path[j] = true; // 标记
                    dfs(i + 1);
                    on_path[j] = false; // 恢复现场
                }
            }
        };

        dfs(0);

        return res;
    }
};
// @lc code=end

