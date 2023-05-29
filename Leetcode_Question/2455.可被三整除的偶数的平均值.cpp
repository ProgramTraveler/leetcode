class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum = 0, cnt = 0;

        for (auto &n : nums) if (n % 3 == 0 && n % 2 == 0) sum += n, cnt ++;

        return sum == 0 ? 0 : (sum / cnt);
    }
};