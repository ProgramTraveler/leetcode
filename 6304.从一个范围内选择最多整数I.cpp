class Solution {
public:

    int maxCount(vector<int>& banned, int n, int maxSum) {
        int sum = 0, res = 0, idx = 1;
        
        //sort(banned.begin(), banned.end());
        
        unordered_map<int, int> ma;
        
        for (int i = 1; i <= n; i ++) ma[i] ++;
        
        for (int i : banned) ma[i] --;
        
        for (int i = 1; i <= n; i ++) {
            if (ma[i] > 0) {
                sum += i;
                
                if (sum > maxSum) break;
                
                else res ++;
            }
        }
        
        return res;
    }
};