class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int res = 0;

        unordered_map<char, int> vowel;
        
        {
            vowel['a'] ++;
            vowel['e'] ++;
            vowel['i'] ++;
            vowel['o'] ++;
            vowel['u'] ++;
        }

        for (int i = left; i <= right; i ++) {
            std::string idx(words[i]);

            int n = idx.size() - 1;

            res += (vowel[idx[0]] && vowel[idx[n]]);
        }

        return res;
    }
};