class Solution {
public:
    int countPoints(string rings) {
        int res = 0;

        unordered_map<int, set<char>> cnt; // 某个杆上的圈的颜色

        for (int i = 0; i < rings.size() - 1; i += 2) {
            cnt[rings[i + 1] - '0'].insert(rings[i]);
        }

        for (auto& [k, v] : cnt) {
            if (v.size() == 3) res ++;
        }
        
        return res;
    }
};