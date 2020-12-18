/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 */

// @lc code=start
class Solution {
public:
    char findTheDifference(string s, string t) {
        //位运算
        int ans = 0;
        for (char i : s)
            ans ^= i;
        for(char i : t) {
            ans ^= i;
        }
        return ans;        
    }
};
// @lc code=end

