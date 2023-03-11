/*
 * @lc app=leetcode.cn id=504 lang=java
 *
 * [504] 七进制数
 */

// @lc code=start
class Solution {
    public String convertToBase7(int num) {
        if (num == 0) return "0";
        
        boolean flag = num < 0; //负数的情况
        num = Math.abs(num);
        StringBuffer dig = new StringBuffer();

        while (num > 0) { //正常的进制转换的算法
            dig.append(num % 7);
            num /= 7;
        }

        if (flag) dig.append('-'); //负数再添加一个负号

        return dig.reverse().toString();
    }
}
// @lc code=end

