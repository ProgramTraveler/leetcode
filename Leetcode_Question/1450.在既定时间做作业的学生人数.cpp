/*
 * @lc app=leetcode.cn id=1450 lang=cpp
 *
 * [1450] 在既定时间做作业的学生人数
 */

// @lc code=start
class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int res = 0;

        /*for (int i = 0; i < startTime.size(); i ++) { //正常的枚举思想
            if (startTime[i] <= queryTime) {
                if (endTime[i] >= queryTime) res ++;
            }
        }*/

        //进行一些修改
        for (int i = 0; i < startTime.size(); i ++) {
            if ((queryTime - startTime[i]) <= (endTime[i] - startTime[i]) && (queryTime - startTime[i] >= 0)) res ++;
        }
        return res;
    }
};
// @lc code=end

