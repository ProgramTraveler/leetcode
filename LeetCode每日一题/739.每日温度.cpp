/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> st;
        vector<int> res(T.size(), 0);
        st.push(0); //单调栈中存的是数字的下标
        for (int i = 1; i < T.size(); i ++) {
            if (T[i] <= T[st.top()])
                st.push(i);
            else {
                while (!st.empty() && T[i] > T[st.top()]) {
                    res[st.top()] = i - st.top();
                    st.pop();
                }
                st.push(i);
            }
        }
        return res;
    }
};
// @lc code=end

