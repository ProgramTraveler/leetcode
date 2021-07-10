/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        
        stack<int> stk;
        int Max=0;
        stk.push(-1); //做栈底标记
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') stk.push(i); //如果遇到'('，就入栈
            
            //如果是')'
            else{
                stk.pop(); //如果前面的'('的都被匹配了，还剩个-1的栈底则-1出栈，放进新的栈底
                if(stk.empty()) stk.push(i); //在栈空时的遇到的第一个')'入栈

                else{
                    Max=max(Max,i-stk.top()); //否则就通过比较更新最大值
                }
            }
        } 
        return Max;
    }
};
// @lc code=end

