class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        // 无顺序要求
        sort(nums.begin(), nums.end());

        int n = nums.size(), m = queries.size();

        vector<int> f(n + 1, 0);

        // f[0] = 0;

        for (int i = 0; i < n; i ++) f[i + 1] = f[i] + nums[i];

        vector<int> res(m);

        for (int i = 0; i < m; i ++) {
            res[i] = upper_bound(f.begin(), f.end(), queries[i]) - f.begin() - 1;
        }

        return res;
    }
};