class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        // 价值是唯一的
        unordered_map<int, int> al;
        vector<vector<int>> res;

        for (int i = 0; i < items1.size(); i ++) al[items1[i][0]] += items1[i][1];
        for (int i = 0; i < items2.size(); i ++) al[items2[i][0]] += items2[i][1];

        for (auto [k, v] : al) res.push_back(initializer_list<int>{k, v});

        sort(res.begin(), res.end());

        return res;

    }
};