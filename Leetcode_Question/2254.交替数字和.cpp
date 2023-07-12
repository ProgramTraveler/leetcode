class Solution {
public:
    int alternateDigitSum(int n) {
        long long res = 0;
        vector<int> cnt;
        int idx = 1;

        while (n) {
            cnt.emplace_back(n % 10);
            n /= 10;
        }

        reverse(cnt.begin(), cnt.end());

        for (int i = 0; i < cnt.size(); i ++) {
            i % 2 == 0 ? idx = 1 : idx = -1;

            res += idx * cnt[i];
        }

        return res;
    }
};