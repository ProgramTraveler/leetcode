/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
       int hash[26]={0}; //记录magazine上的子母数
       for(char x:magazine)
       {
           hash[x-'a']+=1; //记录字母数目
       }
       for(char x:ransomNote)
        {
            hash[x-'a']-=1;//被使用，字母数目减一
            if(hash[x-'a']<0) return false; //如果已经透支了，就返回false
        }
        return true;
    }
};
// @lc code=end

