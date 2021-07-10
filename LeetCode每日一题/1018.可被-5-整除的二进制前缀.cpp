/*
 * @lc app=leetcode.cn id=1018 lang=cpp
 *
 * [1018] 可被 5 整除的二进制前缀
 */

// @lc code=start
//模拟的做法
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> list;
        int prefix = 0;
        int length = A.size();
        for (int i = 0; i < length; i++) {
            prefix = ((prefix << 1) + A[i]) % 5;
            list.emplace_back(prefix == 0);
        }
        return list;
    }
};
// @lc code=end

