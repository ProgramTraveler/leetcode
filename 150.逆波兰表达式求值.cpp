/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> ans;
        for (int i = 0; i < tokens.size(); i ++) {
            if (tokens[i] == "+") {
                int A = ans.top();
                ans.pop();
                int B = ans.top();
                ans.pop();
                ans.push(A + B);
            } else if (tokens[i] == "-") {
                int A = ans.top();
                ans.pop();
                int B = ans.top();
                ans.pop();
                ans.push(B - A);
            } else if (tokens[i] == "*") {
                int A = ans.top();
                ans.pop();
                int B = ans.top();
                ans.pop();
                ans.push(A * B);
            } else if (tokens[i] == "/") {
                int A = ans.top();
                ans.pop();
                int B = ans.top();
                ans.pop();
                ans.push(B / A);
            }else {
                ans.push(stoi(tokens[i]));    
            }
        }
        return ans.top();
    }
};
// @lc code=end

