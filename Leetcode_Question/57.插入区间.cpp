/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // 升序排列
        // 先插入再进行合并
        intervals.push_back({newInterval[0], newInterval[1]});
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;

        for (int i = 0; i < intervals.size();) {
            int tem = intervals[i][1]; // 临时最大值

            int j = i + 1; // 查看下一个区间是否可以合并

            while (j < intervals.size() && intervals[j][0] <= tem) { // 可以合并
                tem = max(tem, intervals[j][1]); // 更新最大值

                //接着往下寻找
                j ++;
            }

            // 保存合并后的区间
            res.push_back({intervals[i][0], tem});

            i = j; // 跳过合并后的区间
        }

        return res;
    }
};
// @lc code=end

