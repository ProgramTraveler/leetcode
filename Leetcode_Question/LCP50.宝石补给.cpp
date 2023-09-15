class Solution {
public:
    int giveGem(vector<int>& gem, vector<vector<int>>& operations) {
        int n = gem.size();

        for (auto oper : operations) {
            int tem = gem[oper[0]] / 2;
            gem[oper[0]] = gem[oper[0]] - tem;
            gem[oper[1]] += tem;
        }

        sort(gem.begin(), gem.end());

        return gem[n - 1] - gem[0];
    }
};