class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int Max = amount + 1;
        vector<int> f(amount + 1, Max);
        f[0] = 0;

        for (int i = 1; i <= amount; i ++) {
           
            for (auto co : coins) {
                if (i - co >= 0) f[i] = min(f[i], f[i - co] + 1);
            }
            
        }

        return f[amount] > amount ? -1 : f[amount];
    }
};