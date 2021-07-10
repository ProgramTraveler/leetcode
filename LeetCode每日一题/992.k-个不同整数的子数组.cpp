/*
 * @lc app=leetcode.cn id=992 lang=cpp
 *
 * [992] K 个不同整数的子数组
 */

// @lc code=start
class Solution {
public:
    int MostArray(vector<int>& A, int k) {
        int left = 0, right = 0; //依旧是左右指针，维持窗口
        int res = 0; //记录k个不同整数的子数组
        int dis = 0; //记录窗口中的不同整数的个数
        vector<int> count(20000 + 1, 0); //记录整数的出现的次数
        //对数组进行遍历
        while (right < A.size()) {
            //如果当前数字出现次数为0
            if (count[A[right]] == 0) 
                dis ++; //说明之前没有出现过，不同整数个数加一
            count[A[right]] ++; //出现的次数加一
            //如果不同整数的个数超过规定值，缩小左窗口
            while (dis > k) {
                //最左边出现的数的次数减一
                count[A[left]] --;
                //如果最左边的数出现次数为0
                if (count[A[left]] == 0)
                    dis --; //说明缩短后，不同整数的个数减一
                left ++; //左窗口继续缩小
            }
            //满足情况的子数组的个数
            res += right - left + 1;
            //右窗口移动
            right ++; 
        }
        return res; //返回最终的结果
    }
    int subarraysWithKDistinct(vector<int>& A, int K) {
        //恰好由 K 个不同整数的子数组的个数 = 最多由 K 个不同整数的子数组的个数 - 最多由 K - 1 个不同整数的子数组的个数
        return MostArray(A, K) - MostArray(A, K - 1);
    }
};
// @lc code=end

