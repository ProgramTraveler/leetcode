/*
 * @lc app=leetcode.cn id=888 lang=cpp
 *
 * [888] 公平的糖果交换
 */

// @lc code=start
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sumA = accumulate(A.begin(), A.end(), 0);
        int sumB = accumulate(B.begin(), B.end(), 0);
        int target = (sumA - sumB) / 2;
        // 默认sort就是从小打大也可以省略 less<int>()
        sort(A.begin(), A.end(), less<int>());
        sort(B.begin(), B.end(), less<int>());

        // 双指针分别指向A和B的开头
        int i = 0;
        int j = 0;
        int nA = A.size();
        int nB = B.size();
        while (i < nA && j < nB)
        {
            int curr = A[i] - B[j];
            if (curr == target)
            {
                return {A[i], B[j]};
            }
            else if (curr > target)
            {
                ++j;
            }
            else
            {
                ++i;
            }
        }

        // 找不到则返回空
        return vector<int>();
    }
};

// @lc code=end

