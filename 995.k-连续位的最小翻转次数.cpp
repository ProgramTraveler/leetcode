/*
 * @lc app=leetcode.cn id=995 lang=cpp
 *
 * [995] K 连续位的最小翻转次数
 */

// @lc code=start
class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int N = A.size();
        queue<int> que;
        int res = 0;
        for (int i = 0; i < N; ++i) {
            if (!que.empty() && i >= que.front() + K) {
                que.pop();
            }
            if (que.size() % 2 == A[i]) {
                if (i + K > N) {
                    return -1;
                }
                que.push(i);
                res ++;
            }
        }
        return res;
    }
};
// @lc code=end

