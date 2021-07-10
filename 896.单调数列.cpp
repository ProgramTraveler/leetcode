/*
 * @lc app=leetcode.cn id=896 lang=cpp
 *
 * [896] 单调数列
 */

// @lc code=start
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool flag = false;
        bool sign = false;

        if (A.size() <= 1) return true;

        for (int i = 1; i < A.size(); i ++) {
            if (A[i] >= A[i - 1]) flag = true;
            else {
                flag = false;
                break;
            }
        }
        for (int i = 1; i < A.size(); i ++) {
            if (A[i] <= A[i - 1]) sign = true;
            else {
                sign = false;
                break;
            }
        }
        return flag || sign;

    }
};
// @lc code=end

