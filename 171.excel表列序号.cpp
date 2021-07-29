/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel表列序号
 */

// @lc code=start
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int number = 0;
        long multiple = 1;
        for (int i = columnTitle.size() - 1; i >= 0; i--) {
            int k = columnTitle[i] - 'A' + 1;
            number += k * multiple;
            multiple *= 26;
        }
        return number;
    }
};
// @lc code=end

