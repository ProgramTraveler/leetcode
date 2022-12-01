/*
 * @lc app=leetcode.cn id=1779 lang=cpp
 *
 * [1779] 找到最近的有相同 X 或 Y 坐标的点
 */

// @lc code=start
class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int res = -1, dom = INT_MAX;

        for (int i = 0; i < points.size(); i ++) {
            if (points[i][0] == x || points[i][1] == y) {
                if (dom > (abs(x - points[i][0]) + abs(y - points[i][1]))) {
                    res = i;
                    dom = abs(x - points[i][0]) + abs(y - points[i][1]);
                }
            }
        }

        return res;
    }
};
// @lc code=end

