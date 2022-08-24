/*
 * @lc app=leetcode.cn id=1460 lang=cpp
 *
 * [1460] 通过翻转子数组使两个数组相等
 */

// @lc code=start
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> m;

        for (int i = 0; i < target.size(); i ++) m[target[i]] ++;

        for (int i = 0; i < arr.size(); i ++) m[arr[i]] --;

        for (auto& [key, value] : m) if (value < 0) return false;

        return true;
    }
};
// @lc code=end

