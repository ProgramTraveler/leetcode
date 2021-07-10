/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) 
    {
        //思路：左边入栈，遇右括号就pop出来和当前匹配
        if(s == "")return true;//空串直接返回true

        stack<char> judge;//栈
        int right=0,left =0;//左括号和右括号计数

        for(int i=0;i<s.length();i++)//遍历每一个字符
        {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')//左括号
            {
                judge.push(s[i]);
                left++;
            }
            else//右括号
            {
                right++;
                if(judge.empty())return false;//如果该出栈时栈为空，说明左右不匹配
                else
                {//这里利用一个性质：右括号的ascii码总是左边加一或加二
                    if(s[i] != judge.top()+1 && s[i] != judge.top()+2)
                    {
                         return false;
                    }
                    judge.pop();
                }
            }
        }
        return right == left? true:false;//必须左右计数一样多才true
    }
};
// @lc code=end

