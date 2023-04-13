class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int res = INT_MAX;

        unordered_map<int, int> al;

        for (auto &n : nums) if (n % 2 == 0) al[n] ++;
        
        int cnt = INT_MIN;

        for (auto &[k, v] : al) cnt = max(v, cnt);

        for (auto &[k, v] : al) if (v == cnt) res = min(res, k);
        

        return cnt > 0 ? res : -1; 
    }
};