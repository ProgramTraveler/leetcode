/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 */

// @lc code=start
class Solution {
public:
    int num_sum(int num) {

        if (num / 10 == 0) return num; //如果这个数是个位数，就返回这个值
        
        int temp = 0; //保存两位数相加的结果，作为新的num

        //循环求解，把num的各个位数字相加
        while (num > 0) {
            temp += num % 10;
            num = num / 10;
        }

        //新数字作为新的num传入下一次的求和函数
        num = num_sum(temp);
        return num;
    }
    int addDigits(int num) {
        return num_sum(num);
    }
};
// @lc code=end

