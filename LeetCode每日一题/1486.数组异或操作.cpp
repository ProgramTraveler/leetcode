/*
 * @lc app=leetcode.cn id=1486 lang=cpp
 *
 * [1486] 数组异或操作
 */

// @lc code=start
class Solution {
public:
    int xorOperation(int n, int start) {
        int ans = 0;
        //按题意模拟即可
        for (int i = 0; i < n; i ++)
            ans ^= (start + 2 * i); 
        return ans;
    }
};
// @lc code=end

