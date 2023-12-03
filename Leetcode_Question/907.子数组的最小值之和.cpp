const int MOD = 1e9 + 7;
using ll = long long;
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        arr.emplace_back(-1);
        stack<int> st; // 存的是下标
        st.push(-1);

        ll res = 0;
        for (int i = 0; i <arr.size(); i ++) {
            while (st.size() > 1 && arr[i]  < arr[st.top()]) {
                int last = st.top();
                st.pop();
                res = (res + (ll) arr[last] * (last - st.top()) * (i - last)) % MOD;
            }
            st.push(i);
        }

        return res;
    }
};