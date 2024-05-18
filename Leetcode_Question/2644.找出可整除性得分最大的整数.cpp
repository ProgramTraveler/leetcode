/*
 * @lc app=leetcode.cn id=2644 lang=cpp
 *
 * [2644] 找出可整除性得分最大的整数
 */

// @lc code=start
class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int res = -1;
        int max_cnt = -1;
        ranges::sort(nums, greater());
        for (const int& d : divisors) {
            int temp_cnt = 0;
            for (const int& n : nums) {
                if (n < d) {
                    break;
                }
                if (n % d == 0) {
                    temp_cnt ++;
                }
            }
            if (temp_cnt > max_cnt || (temp_cnt == max_cnt && d < res)) {
                res = d;
                max_cnt = temp_cnt;
            }
        }
        return res;
    }
};
// @lc code=end

