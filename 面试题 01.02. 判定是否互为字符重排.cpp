class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        map<char, int> m;

        if (s1.size() != s2.size()) return false;

        for (int i = 0; i < s1.size(); i ++) m[s1[i]] ++;
        for (int i = 0; i < s2.size(); i ++) m[s2[i]] --;

        for (auto& [key , val] : m) if (val != 0) return false;

        return true;
    }
};