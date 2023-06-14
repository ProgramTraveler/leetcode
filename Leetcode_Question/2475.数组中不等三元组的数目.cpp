/*class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        // 排列组合问题
        // 但是是三三组合问题
        // 脑子有点不好使了 哈哈哈

        vector<int> cnt;

        int res = 0, n = nums.size();

        function<void(int)> dfs = [&](int i) {
            if (i > n) return;

            if (cnt.size() == 3) {
                cout << cnt[0] << ' ' << cnt[1] << ' ' << cnt[2] << endl;
                if (cnt[0] != cnt[1] && cnt[0] != cnt[2] && cnt[1] != cnt[2]) res ++; // 还要考虑坐标位置
            }


            dfs(i + 1); // 不选

            // 选
            cnt.emplace_back(nums[i]);
            dfs(i + 1);
            cnt.pop_back();
        };

        dfs(0);

        return res;
    }
};*/

class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        unordered_map<int, int> count;
        for (auto x : nums) {
            count[x]++;
        }

        int res = 0, n = nums.size(), t = 0;
        for (auto [_, v] : count) {
            res += t * v * (n - t - v);
            t += v;
        }
        return res;
    }
};