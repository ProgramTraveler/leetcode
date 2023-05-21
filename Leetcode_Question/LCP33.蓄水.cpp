class Solution {
public:
    int storeWater(vector<int>& bucket, vector<int>& vat) {
        int cnt = INT_MIN;

        for (int i = 0; i < vat.size(); i ++) cnt = max(cnt, vat[i]);

        if (cnt == 0) return 0;

        int res = INT_MAX;

        for (int i = 1; i <= cnt; i ++) { // 枚举蓄水次数
            int x{}, y{};

            for (int j = 0; j < vat.size(); j ++) {
                x = (vat[j] % i == 0) ? vat[j] / i : vat[j] / i + 1; // 需要桶的等级

                y += max(0, x - bucket[j]); // 升级桶的次数
                
                // y += max(0, (vat[j] + i - 1) / i - bucket[j]); // 升级桶的次数
            }

            res = min(res, i + y);
        }

        return res;
    }
};