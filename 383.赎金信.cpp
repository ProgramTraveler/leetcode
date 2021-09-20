/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int ap[26] = {0}; //记录杂志中相应字母的个数
        for (int i = 0; i < magazine.size(); i ++)
            ap[magazine[i] - 'a'] ++;
        for (int i = 0; i < ransomNote.size(); i ++) { 
            if (ap[ransomNote[i] - 'a'] == 0) return false;
            else ap[ransomNote[i] - 'a'] --;
        }
        return true;
    }
};
// @lc code=end

