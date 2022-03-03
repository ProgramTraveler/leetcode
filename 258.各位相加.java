/*
 * @lc app=leetcode.cn id=258 lang=java
 *
 * [258] 各位相加
 */

// @lc code=start
class Solution {
    public int sum(int n) {
        if (n / 10 == 0) return n; //个位数直接返回

        int temp = 0; //临时变量
        while (n > 0) {
            temp += n % 10;
            n = n / 10;
        }
        
        return sum(temp);
    }

    public int addDigits(int num) {
       return sum(num);
    }
}
// @lc code=end

