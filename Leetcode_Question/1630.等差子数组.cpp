/*
 * @lc app=leetcode.cn id=1630 lang=cpp
 *
 * [1630] 等差子数组
 */

// @lc code=start
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        // 只要是一个等差数组 那么一定是有序的 要么是从大到小 要么是从小到大 x <= x + d || x >= x +d

        vector<bool> res;
        vector<int> cnt;
        bool idx = true;

        // l 和 r 的长度是相等的
        for (int i = 0; i < l.size(); i ++) {
            cnt.clear();
            idx = true;

            for (int j = l[i]; j <= r[i]; j ++) cnt.push_back(nums[j]);

            sort(cnt.begin(), cnt.end());

            int d = cnt[1] - cnt[0];

            for (int k = 0; k < cnt.size(); k ++) {
                idx = (cnt[k] == cnt[0] + k * d ? true : false);

                if (!idx) break;
            }

            // cout << idx << ' ' << l[i] << ' ' << r[i] << endl;

            res.push_back(idx);
        }

        return res;
    }
};
// @lc code=end

