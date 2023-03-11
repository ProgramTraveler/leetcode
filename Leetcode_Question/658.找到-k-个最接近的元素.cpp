/*
 * @lc app=leetcode.cn id=658 lang=cpp
 *
 * [658] 找到 K 个最接近的元素
 */

// @lc code=start
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size() - k;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (x - arr[mid] > arr[mid + k - 1] - x) left = mid + 1;

            else right = mid;
        } 

        if (left > 0 && abs(arr[left - 1] - x) <= abs(arr[left + k - 1] - x)) --left;

        return vector<int> (arr.begin() + left, arr.begin() + left + k);
    }
};
// @lc code=end

