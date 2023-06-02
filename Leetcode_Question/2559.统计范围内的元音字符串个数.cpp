class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<bool> idx; // 下标为 i 的字符串是否符合

        function<bool(string)> func = [&](string s) -> bool {
            int n = s.size() - 1;

            bool fir = (s[0] == 'a') || (s[0] == 'e') || (s[0] == 'i') || (s[0] == 'o') || (s[0] == 'u');
            bool end = (s[n] == 'a') || (s[n] == 'e') || (s[n] == 'i') || (s[n] == 'o') || (s[n] == 'u');

            if (fir && end) return true;

            return false;
        };

        for (auto &s : words) {
            idx.emplace_back(func(s));
        }

        vector<int> res;

        // 前缀和
        vector<int> f(idx.size() + 1, 0);

        for (int i = 1; i < f.size(); i ++) f[i] = f[i - 1] + idx[i - 1];

        for (int i = 0; i < queries.size(); i ++) {
            int fir = queries[i][0], end = queries[i][1];

            res.emplace_back(f[end + 1] - f[fir]);
        }

        return res;
         
    }
};