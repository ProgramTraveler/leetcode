class Solution {
public:
    bool check(const vector<int>& e1, const vector<int>& e2) {
        if (e1[0] == e2[0] || e1[0] == e2[1] || e1[1] == e2[0] || e1[1] == e2[1]) return true;

        if (e1[0] > e2[0] && e1[0] < e2[1]) return true;

        if (e1[0] < e2[0] && e1[1] > e2[0]) return true;

        return false;
    }

    vector<int> func(const vector<string>& event) { // 将时间转为数字
        vector<int> res;

        for (auto s : event) {
            int cnt = 0;
            
            for (auto c : s) if (isdigit(c)) cnt = cnt * 10 + (c - '0');
        
            res.push_back(cnt);
        }

        return res;
    }
    bool haveConflict(vector<string>& event1, vector<string>& event2) {

        return check(func(event1), func(event2));

    }
};