/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string str) 
    {
        int ans=0; //保存答案
        bool flag=true; //正负符号判定（初始为正）
        int num=0; //记录在数字之前的下标
        while(str[num]==' ') num++; //如果遇到空格就继续往下走

        if(str[num]=='-') flag=false; //遇到的是负号，flag转为false

        if(str[num]=='-' || str[num]=='+') num++; //再把下标向后一位

        //开始向后遍历所有是数字的字符
        for(;num<str.size() && isdigit(str[num]);num++)
        {
            //溢出判断
            if(ans<INT_MIN/10 || (ans==INT_MIN/10 && str[num]-'0'>8)) return INT_MIN;
            if(ans>INT_MAX/10 || (ans == INT_MAX/10 && str[num]-'0'>7)) return INT_MAX;

            //对于正负号做出相应的操作
            if(flag==false)
            {
                ans=ans*10-(str[num]-'0');
            }
            else
            {
                ans=ans*10+(str[num]-'0');
            }
            

        }

        return ans;    
    }
};
// @lc code=end

