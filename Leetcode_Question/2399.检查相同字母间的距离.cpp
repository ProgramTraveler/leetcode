class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        // 不就是检查 s 中两个字母中的字母数是不是和 distance 一样？
        // 说话拐弯抹角的
        unordered_map<int, vector<int>> al;

        for (int i = 0; i < s.size(); i ++) al[s[i] - 'a'].push_back(i);

        for (auto &[k, v] : al) {
            if (v[1] - v[0] - 1 != distance[k]) return false;
        }

        return true;
    }
};