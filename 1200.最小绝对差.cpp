/*
 * @lc app=leetcode.cn id=1200 lang=cpp
 *
 * [1200] 最小绝对差
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;

        int best_num = INT_MAX;

        sort(arr.begin(), arr.end()); //对原数组进行排序

        for (int i = 0; i < arr.size() - 1; i ++) {
            if (int de = arr[i + 1] - arr[i]; de < best_num) { //如果当前差值比预期的小，更新ans
                best_num = de;
                ans = {{arr[i], arr[i + 1]}}; //这个更新格式
            } else if (de == best_num) {
                ans.emplace_back(initializer_list<int>{arr[i], arr[i + 1]}); //这个更新手法
            }
        }

        return ans;
    }
};
// @lc code=end

