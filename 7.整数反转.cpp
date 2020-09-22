/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
    int ans = 0;
    while (x != 0) 
        {
            int pop = x % 10;
            //对数值进行越界判断
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && pop > 7)) 
                return 0;
            if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && pop < -8)) 
                return 0;
            //没有溢出就正常操作
            ans = ans * 10 + pop;
            x=x / 10;
        }
        return ans;
    }
};

// @lc code=end

