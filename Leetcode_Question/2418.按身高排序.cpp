class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string> res;

        unordered_map<int, int> al; // 身高对应的下标

        for (int i = 0; i < heights.size(); i ++) al[heights[i]] = i;

        sort(heights.begin(), heights.end(), greater<int>());

        for (int i = 0; i < heights.size(); i ++) res.push_back(names[al[heights[i]]]);
        

        return res;
    }
};