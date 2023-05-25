class Solution {
public:
    vector<int> func(string s) {
        vector<int> res;

        for (int i = 1; i < s.size(); i ++) res.emplace_back((s[i] - 'a') - (s[i - 1] - 'a'));

        return res;
    }

    string oddString(vector<string>& words) {
        map<vector<int>, int> cnt;
        map<vector<int>, int> idx;
        for (int i = 0; i < words.size(); i ++) {
            cnt[func(words[i])] ++;

            idx[func(words[i])] = i;

            // if (cnt.size() > 2) break;

        }

        string res = "";

        for (auto &[k, v] : cnt) {
            if (v == 1) {
                res = words[idx[k]];

                break;
            }
        }

        return res;

    }
};