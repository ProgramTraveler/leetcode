/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */

// @lc code=start
class Solution {
public:
    void Sta(string a,stack<char> &A){
        //将字符串中的字符存入栈中，同时在遇到退格符后进行操作
        for(int i=0;i<a.size();i++){
            //如果不是退格符，将字符存入栈中
            if(a[i]!='#') A.push(a[i]);
            //如果是退格符，而且栈不为空，就把栈顶元素弹出
            else if(a[i]=='#' && !A.empty()){
                A.pop();
            }else continue; //其他情况就是可以直接忽略（当遇到退格符，但栈为空）
        }
    }
    bool backspaceCompare(string S, string T) {
        //对S字符串退格
        Sta(S,S_tmp);
        //对T字符串退格
        Sta(T,T_tmp);
        //对退格后的字符串进行比较
        while(!S_tmp.empty() && !T_tmp.empty()){
            //如果字符不相等，直接返回false
            if(S_tmp.top()!=T_tmp.top()) return false;
            //否则就弹出两个栈的元素，再去做比较
            else{
                S_tmp.pop();
                T_tmp.pop();
            }
        }
        //这个判断是为了判断两个完成比较，而且是相同的
        if(S_tmp.empty() && T_tmp.empty()) return true;
        else return false;
        
    }
private:
    stack<char> S_tmp;
    stack<char> T_tmp;
};
// @lc code=end

