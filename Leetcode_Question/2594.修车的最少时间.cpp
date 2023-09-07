class Solution {
public:
    using ll = long long;
    long long repairCars(vector<int>& ranks, int cars) {
        // long long 类型
        // 所有机械工可以同时修理车辆
        // 如何分配？
        // 同时修相同数量的车 能力值越高的花的时间越长？这太不合理了
        // 注意传参的数据类型 以及运算的溢出
        ll l = 1, r = 1ll *ranks[0] * cars * cars;
        auto check = [&] (ll m) {
            ll cnt = 0;

            for (auto r : ranks) {
                cnt += sqrt(m / r);
            }

            return cnt >= cars;
        };

        while (l < r) {
            ll m = l + (r - l) / 2; // 防止数据溢出 
            if (check(m)) { // 如果可以修理的车辆超过了 cars 说明分配的时间长了
                r = m;
            } else { // 否则就是分配的时间短了
                l = m + 1;
            }
        }

        return l;
    }
};