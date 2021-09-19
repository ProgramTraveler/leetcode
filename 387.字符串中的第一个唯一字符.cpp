/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

// @lc code=start
class Solution {
public:
    int firstUniqChar(string s) {
        //因为全是小写，建立一个26个字母的数组
        int ap[26] = {0}; 
        for (int i = 0; i < s.size(); i ++) //记录出现的次数
            ap[s[i] - 'a'] ++;
        for (int i = 0; i < s.size(); i ++) { //按顺序查找，返回第一个出现的字母下标
            if (ap[s[i] - 'a'] == 1)
                return i; 
        }
        return -1;
    }
};
// @lc code=end

