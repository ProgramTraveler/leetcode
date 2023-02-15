/*
 * @lc app=leetcode.cn id=1124 lang=cpp
 *
 * [1124] 表现良好的最长时间段
 */

// @lc code=start
class Solution {
public:
    int longestWPI(vector<int>& hours) { // 直接滑动窗口
        /*int l = 0, r = 0, cnt = 0;

        int res = 0;

        int n = hours.size();

        while (l < n) {
            //cout << l << ' ' << n << ' ' << (l < n) << endl;
            r = l;

            cnt = 0;

            if (hours[l] > 8) {
                cnt ++;

                while (cnt > 0 && r < n) {
                    r ++;

                    if (hours[r] > 8) cnt ++;
                    else cnt --;
                }

                int tem = r - l;

                if (r == (n - 1)) tem += 1;

                res = max(res, tem);
            }

            l ++;
        }

        l = n - 1;

        while (l >= 0) {
            r = l;

            cnt = 0;

            if (hours[l] > 8) {
                cnt ++;

                while (cnt > 0 && r > 0) {
                    r --;

                    if (hours[r] > 8) cnt ++;
                    else cnt --;
                }

                int tem = l - r;

                if (r == 0) tem += 1;

                res = max(res, tem);
            }

            l --;
        }

        return res;*/

        int n = hours.size(), ans = 0, s[n + 1]; // 前缀和
        stack<int> st;
        st.push(s[0] = 0);
        for (int j = 1; j <= n; ++j) {
            s[j] = s[j - 1] + (hours[j - 1] > 8 ? 1 : -1);
            if (s[j] < s[st.top()]) st.push(j); // 感兴趣的 j
        }
        for (int i = n; i; --i)
            while (!st.empty() && s[i] > s[st.top()]) {
                ans = max(ans, i - st.top()); // [栈顶,i) 可能是最长子数组
                st.pop();
            }
        return ans;


    }
};
// @lc code=end

