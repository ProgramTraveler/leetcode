/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

// @lc code=start
class Solution {
public:
    int firstUniqChar(string s) 
    {
        map<int,int> Map;//<关键字,关键字的值>（每个关键字在map里出现一次）
        for(char x:s) Map[x]++; //记录关键字出现的次数
        //查找只出现一次的关键字，并按题目要求返回
        for(int i=0;i<s.length();i++)
        {
            if(Map[s[i]]==1) return i;
        }
        return -1;
    }
};
// @lc code=end

