/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        //使用数学的方法来进行解决
         //4=1+3 9=1+3+5 16=1+3+5+7以此类推，模仿它可以使用一个while循环，不断减去一个从1开始不断增大的奇数，若最终减成了0，说明是完全平方数，否则不是
        int index = 1;
        while (num > 0) {
            num -= index;
            index += 2;
        }
        return num == 0 ? true : false; 
    }
};
// @lc code=end

