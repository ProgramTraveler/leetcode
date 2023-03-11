/*
 * @lc app=leetcode.cn id=1828 lang=cpp
 *
 * [1828] 统计一个圆中点的数目
 */

// @lc code=start
class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        // 计算圆的方程 ？

        int n = queries.size();

        vector<int> res(n, 0); // n 个结果

        for (int i = 0; i < points.size(); i ++)  {
            int x = points[i][0], y = points[i][1];

            for (int j = 0; j < queries.size(); j ++) {
                int cir_x = queries[j][0], cir_y = queries[j][1], r = queries[j][2];

                if ((x - cir_x) * (x - cir_x) + (y - cir_y) * (y - cir_y) <= r * r) res[j] ++;
            }
        }

        return res;
    }
};
// @lc code=end

