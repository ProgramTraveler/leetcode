class Solution {
public:
    int minCount(vector<int>& coins) {
        int res = 0;

        for (auto c : coins) {
            res += (c % 2) + (c / 2);
        }

        return res;
    }
};