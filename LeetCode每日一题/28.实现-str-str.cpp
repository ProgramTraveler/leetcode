/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        //如果needle是空字符串，就直接返回0
        if(needle.size()==0) return 0;
        vector<int> q; //记录和needle匹配的下标
        vector<int> h; //记录haystack的下标（用于更新）
        int flag=0; //用于更新needle的下标
        for(int i=0;i<haystack.size();i++){
            //把从i开始的下标存储
            h.push_back(i);
            //如果两个字符相等
            if(needle[flag]==haystack[i] && flag<needle.size()){
                //把相等的下标存储
                q.push_back(i);
                //同时flag++，更新needle
                flag++;
            }else if(needle[flag]!=haystack[i]){ //如果不想等的话
                //把之前记录的下标清空
                q.clear();
                //更新i
                i=h[0];
                //把之前记录的i的下标清空
                h.clear();
                //重置flag
                flag=0;
            }
            //如果q里面的值的数量和needle的数量相等，就把第一个下标返回
            if(q.size()==needle.size()) return q[0];
        }
        //如果没有就返回-1
        return-1;

    }
};
// @lc code=end

