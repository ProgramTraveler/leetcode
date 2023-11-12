class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        //  二分
        sort(potions.begin(), potions.end());
        vector<int> res;
        for (auto i : spells) {
            long long t = (success + i - 1 ) / i - 1;

            res.emplace_back(potions.size() - (upper_bound(potions.begin(), potions.end(), t) - potions.begin()));
        }
        return res;
    }
};