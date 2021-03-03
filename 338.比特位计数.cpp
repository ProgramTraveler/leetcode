/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start
class Solution {
public:
    int lowbit(int n) {
        return n & (-n);
    }
    vector<int> countBits(int num) {
        vector<int> res;
        for (int i = 0; i <= num; i ++) {
            int temp = 0;
            int index = i;
            while (index) {
                index -= lowbit(index);
                temp ++;
            }
            res.push_back(temp);
        }
        return res;
    }
};
// @lc code=end

