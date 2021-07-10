/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) 
    {
       int count=0; //保存单词的长度
       //开始从后面开始遍历
       for(int i=s.length()-1;i>=0;i--)
       {
           //如果遇到空格，分两种情况考虑
           if(s[i]==' ')
           {
               //如果是还没遇到单词，继续遍历
               if(count==0) continue;
               //如果是在单词前的空格，说明这个单词已经结束。结束遍历
               else break;
           }
           //长度加一
           count++;
       }
       return count;     
    }
};
// @lc code=end

