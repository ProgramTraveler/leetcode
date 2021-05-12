/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 */

// @lc code=start
class Solution {
public:
/*      思路：
    转化成 26进制 但不是单纯的26进制 范围是【1-26】没有0；
    所以应该对应0-25；
    在columnNumber == 26的时候 需要进行判断
*/
    string convertToTitle(int columnNumber) {
        string res;
        while (columnNumber > 0) {   
            if(columnNumber% 26 == 0) {
                res = 'Z' + res; 
                columnNumber = columnNumber/26 -1; //columnNumber 赋值为-1，结束循环；
            }
            else {
                res = static_cast<char>('A'+(columnNumber % 26 - 1)) + res;
                //static_cast<char>相当于c语言的强转#（char），不懂的可以自行百度c++11 四种类型转换
                columnNumber = columnNumber/26;
            }
        }
        return res;
    }
};
// @lc code=end

