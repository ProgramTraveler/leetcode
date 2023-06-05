/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H 指数
 */

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
        // 傻鸟题目描述
        sort(citations.begin(), citations.end(), greater<int>());

        int res = 0;

        for (int i = 0; i < citations.size(); i ++) {
            if (citations[i] <= i) break;

            res ++;
        }

        return res;
    }
};
// @lc code=end

