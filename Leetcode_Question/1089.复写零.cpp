/*
 * @lc app=leetcode.cn id=1089 lang=cpp
 *
 * [1089] 复写零
 */

// @lc code=start
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        //使用栈的方式来进行记录，但是会有bug，所以改为队列的方式
        /*stack<int> st;
        int num = arr.size();

        for (int i = 0; (i < arr.size()) && (num > 0); i ++) {
            cout << arr[i] << "====" << (i < arr.size()) << "====" << (num > 0) << "----" << num << endl;
            if (arr[i] > 0) {
                st.push(arr[i]);
                num --;
            } else {
                st.push(0);
                st.push(0);
                num -= 2;
            }
        }

        for (int i = arr.size() - 1; i >= 0 && !st.empty(); i --) {
            arr[i] = st.top();
            st.pop();
        }*/

        queue<int> qu;
        int num = arr.size();

        for (int i = 0; i < arr.size() && num > 0; i ++) {
            if (arr[i] > 0) {
                qu.push(arr[i]);
                num --;
            }
            else {
                qu.push(0);
                qu.push(0);
                num -= 2;
            }
        }

        for (int i = 0; i < arr.size(); i ++) {
            arr[i] = qu.front();
            qu.pop();
        }
    }
};
// @lc code=end

