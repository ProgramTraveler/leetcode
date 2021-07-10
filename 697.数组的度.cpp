/*
 * @lc app=leetcode.cn id=697 lang=cpp
 *
 * [697] 数组的度
 */

// @lc code=start
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> left, right, counter;
        int degree = 0;
        for (int i = 0; i < nums.size(); ++i) {
            cout<<left.count(nums[i])<<endl;
            if (!left.count(nums[i]))
                left[nums[i]] = i;
            right[nums[i]] = i;
            counter[nums[i]] ++;
            degree = max(degree, counter[nums[i]]);
        }
        int res = nums.size();
        for (auto& kv : counter) {
            if (kv.second == degree) {
                res = min(res, right[kv.first] - left[kv.first] + 1);
            }
        }
        return res;
    }
};

// @lc code=end

