/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */

// @lc code=start
class Solution {
private:
    set<char> dict = {'a','o','e','i','u','A','O','E','I','U'};
public:
    // 题解：首尾指针，类比快排代码
    string reverseVowels(string& s) {
        int i = 0,j = s.size() - 1;
        while(i < j)
        {
            while(!dict.count(s[i]) && i < j) i ++;
            while(!dict.count(s[j]) && i < j) j --;
            if( i < j) swap(s[i ++], s[j --]);
        }
        return s;
    }
};
// @lc code=end

