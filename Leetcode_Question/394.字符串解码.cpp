class Solution {
public:
    string decodeString(string s) {
        string ans;
        stack<pair<int, int>> stk;
        int count = 0;
        for (auto x : s) {
            if (isdigit(x)) 
                count = 10 * count + (x - '0');
            else if (x == '[') {
                stk.push({count, ans.size()});
                count = 0;
            }
            else if (isalpha(x)) 
                ans += x;
            else if (x == ']') {
                int n = stk.top().first;
                string str = ans.substr(stk.top().second, ans.size() - stk.top().second);
                for (int i = 0; i < n - 1; i++) {
                    ans += str;
                }
                stk.pop();
            }
        }
        return ans;
    }
}; 