class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        // 数组中的元素都不相同
        // 数据量不是很大，要不试试 dfs？
        int n = nums.size();

        unordered_map<int, int> cnt;

        int res = 0;

        for (int i = 0; i < n; i ++) { // 还以为有什么好方法，结果还是两层循环，虽然数据量不是很大
            for (int j = i + 1; j < n; j ++) {
                cnt[nums[i] * nums[j]] ++;
            }
        }

        // 数学推导有点东西
        for (auto &[k, v] : cnt) {
            res += v * (v - 1) * 4;
        }

        return res;
    }
};