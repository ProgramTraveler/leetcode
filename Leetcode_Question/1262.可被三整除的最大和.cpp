/*
 * @lc app=leetcode.cn id=1262 lang=cpp
 *
 * [1262] 可被三整除的最大和
 */

// @lc code=start
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        // 组合
        /*
        超时了        

        int cnt = 0;

        int sum = 0, n = nums.size();

        function<void(int)> dfs = [&](int i) {
            if (sum % 3 == 0) cnt = max(cnt, sum);
            
            if (i >= n) return;


            dfs(i + 1);

            sum += nums[i];
            dfs(i + 1);
            sum -= nums[i]; 
        };

        dfs(0);

        return cnt;*/

        // 换个贪心的思想
        int s = accumulate(nums.begin(), nums.end(), 0);

        if (s % 3 == 0) return s;

        vector<int> a[3];

        for (int x : nums) a[x % 3].push_back(x);

        sort(a[1].begin(), a[1].end());
        sort(a[2].begin(), a[2].end());

        if (s % 3 == 2) swap(a[1], a[2]);

        int ans = a[1].size() ? s - a[1][0] : 0;

        if (a[2].size() > 1) ans = max(ans, s - a[2][0] - a[2][1]);

        return ans;
    }
};
// @lc code=end

