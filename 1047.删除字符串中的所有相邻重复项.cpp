/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> st;
        if (S.size() <= 1) return S;
        st.push(S[0]);
        for (int i = 1; i < S.size(); i ++) {
            if (st.empty())
                st.push(S[i]);
            else if (st.top() != S[i])
                st.push(S[i]);
            else 
                st.pop();
        }
        string s;
        while (!st.empty()) {
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
// @lc code=end

