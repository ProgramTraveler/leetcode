/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int start=0; // 记录头指针
        int end=0; // 记录尾指针
        int MaxLength=0; // 记录最大的字符串
        int len=0;   // 记录字符的长度
        while(end<s.length())
        {
            //cout<<"1"<<endl;
            for(int i=start;i<end;i++) // 开始和之前的字符比较是否有重复的
            {
                //cout<<"2"<<endl;
                if(s[i]==s[end]) // 如果有重复的
                {
                    MaxLength=max(MaxLength,len); //比较长度，赋最大值
                    start=i+1; // 更新start的位置
                    len=end-start; //更新len的长度
                    break;
                }
            }
            end++; 
            len++;
        }
        MaxLength=max(MaxLength,len); //防止有遗漏，再比较一次（也是防止当输入字符串为“ ”这样的情况，无法在循环里更新MaxLength的情况）
        return MaxLength;
    }
};
// @lc code=end

