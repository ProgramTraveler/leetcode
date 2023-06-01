class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        // 组合问题 dfs
        // 唯一不同的是 k 个的组合问题
        // dfs 超时
        // 如果题目中有「最大化最小值」或者「最小化最大值」一般都是二分答案 请记住这个套路
        
        sort(price.begin(), price.end());

        auto f = [&](int d) -> int {
            int cnt = 1, pre = price[0];

            for (int p : price) {
                if (p >= pre + d) cnt ++, pre = p;
            }

            return cnt;
        };

        int left = 0, right = (price.back() - price[0]) / (k - 1) + 1;
        while (left + 1 < right) { // 开区间不为空
            // 循环不变量
            // f(left) >= k
            // f(right) < k
            int mid = left + (right - left) / 2;
            (f(mid) >= k ? left : right) = mid;
        }

        return left;

    //     int res = INT_MIN;

    //     int n = price.size();

    //     vector<int> tem;

    //     function<void(int)> dfs = [&](int i) {
    //         if (tem.size() == k) {
    //             /*
    //                 这样写果然是超时了 关键还是找出 k 个数中的最小绝对差

    //             int f = INT_MAX;

    //             for (int i = 0; i < tem.size(); i ++) {
    //                 for (int j = i + 1; j < tem.size(); j ++) f = min(f, abs(tem[i] -tem[j]));
    //             }

    //             res = max(res, f);
    //             */

    //             /*
    //                 优化了一下还是超时 测试后发现是 dfs 超时了

    //             sort(tem.begin(), tem.end());

    //             int f = INT_MAX;
    //             for (int i = 1; i < tem.size(); i ++) f = min(f, abs(tem[i] - tem[i - 1]));

    //             res = max(res, f);*/

    //             return;
    //         }

    //         if (i == n) return;
          

    //         dfs(i + 1); // 不选

    //         // 选
    //         tem.push_back(price[i]);
    //         dfs(i + 1);
    //         tem.pop_back();

    //         return;
    //     };

    //     dfs(0);

    //     return res;
    }
};