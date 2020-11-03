/*
 * @lc app=leetcode.cn id=941 lang=cpp
 *
 * [941] 有效的山脉数组
 */

// @lc code=start
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int st = 0;
        for (int i = 1; i < A.size(); i++) {
            switch (st) {
                case 0: 
                    if (A[i] <= A[i - 1]) return false;
                    st = 1;
                    break;
                case 1:
                    if (A[i] == A[i - 1]) return false;
                    if (A[i] < A[i - 1]) {
                        st = 2;
                    }
                    break;
                case 2:
                    if (A[i] >= A[i - 1]) return false;
                    break;
            }
        }
        return st == 2;
    }
};


// @lc code=end

