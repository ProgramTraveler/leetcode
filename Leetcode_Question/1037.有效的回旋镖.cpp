/*
 * @lc app=leetcode.cn id=1037 lang=cpp
 *
 * [1037] 有效的回旋镖
 */

// @lc code=start
class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        //数学方法判断是否在一条直线上
        return ((points[1][0] - points[0][0]) * (points[2][1] - points[1][1]) -
                (points[1][1] - points[0][1]) * (points[2][0] - points[1][0]) != 0); 
    }
};
// @lc code=end

