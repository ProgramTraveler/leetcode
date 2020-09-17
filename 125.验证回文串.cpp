/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s)
    {
        for(int i=0,j=s.length()-1;i<j;i++,j--)
        {
            while(!isalnum(s[i]) && i<j) i++; //判断s[i]是否为字母
            while(!isalnum(s[j]) && i<j) j--;
            if(toupper(s[i])!=toupper(s[j])) return false; //ytoupper(将小写字母变为大写字母)
        }
        return true;
    }
};
// @lc code=end

