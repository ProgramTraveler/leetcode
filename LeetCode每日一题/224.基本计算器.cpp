/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        int ans=0; 
        stack<int> stk;
        int flag=1;
        for(int i=0;i<s.size();i++){
            int temp=0;
            //如果遇到的是数字
            if(s[i]>='0'){
                //这个循环是为了把像'123'这样的字符串转换为int型的123
                while(i<s.size() && s[i]>='0'){
                temp=temp*10+(s[i]-'0');
                i++;
                }
                //把答案加上（按数字之前的符号）
                ans+=temp*flag;
            }
            //因为i在while里已经更新了，再次判断后面是正负号，还是括号
            if(s[i]=='+') flag=1;

            else if(s[i]=='-') flag=-1;
            //如果是'('就把之前计算结果和括号前的符号才存栈中
            else if(s[i]=='('){
                stk.push(ans);
                stk.push(flag);
                //把计算的和以及符号重新初始化
                ans=0;
                flag=1;
            //如果遇到了反括号，说明这一小段的结果结束了
            }else if(s[i]==')'){
                //把括号前的符号给括号内的计算结果
                ans*=stk.top();
                //出栈
                stk.pop();
                //再加上前面计算的和
                ans+=stk.top();
                stk.pop();
            }
        }
        return ans;
    }
};
// @lc code=end

