/*
 * @lc app=leetcode.cn id=905 lang=cpp
 *
 * [905] 按奇偶排序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> a;
        vector<int> b;
        for (int i = 0; i < A.size(); i ++) 
            A[i] % 2 == 0 ? a.push_back(A[i]) : b.push_back(A[i]);
        for (int i  = 0; i < b.size(); i ++)
            a.push_back(b[i]);
        return a;
    }
};
// @lc code=end

