/*
 * @lc app=leetcode.cn id=1742 lang=cpp
 *
 * [1742] 盒子中小球的最大数量
 */

// @lc code=start
class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        int res = 0;

        unordered_map<int, int> cnt; // 记录每个盒子中有多少小球

        for (int i = lowLimit; i <= highLimit; i ++) { // 很朴素的思想
            int box_num = 0, x = i;

            while (x) box_num += x % 10, x /= 10; // 这一步也是平平无奇
            
            cnt[box_num] ++;

            res = max(res, cnt[box_num]);
        }

        return res;
    }
};
// @lc code=end

