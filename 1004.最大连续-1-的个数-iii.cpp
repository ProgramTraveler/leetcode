/*
 * @lc app=leetcode.cn id=1004 lang=cpp
 *
 * [1004] 最大连续1的个数 III
 */

// @lc code=start
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int ans = 0; 
        int left = 0, right = 0; //维持窗口的大小
        int zero = 0; //记录窗口中零出现的个数
        while (right < A.size()) {
            //当窗口中出现0
            if (A[right] == 0)
                zero ++; //零的个数加一
            //当窗口中零的个数超过了限定的值
            while (zero > K) {
                //开始对左窗口边界进行移动
                if (A[left] == 0)
                    zero --;
                left ++;
            }
            //再移动右边界
            right ++;
            //保留窗口的长度
            ans = max(right - left, ans);
        }
        //返回最后的结果
        return ans;
    }
};
// @lc code=end

