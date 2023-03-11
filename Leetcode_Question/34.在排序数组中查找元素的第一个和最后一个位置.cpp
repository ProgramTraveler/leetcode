/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) { // 看见时间复杂度直接二分
        int sta = nums.size(), end = nums.size();

        int l = 0, r = nums.size() - 1;

        bool lower = true;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            /*if (nums[mid] == target) res.push_back(mid); // 找到了位置后 l 和 r 应该怎么去移动 ?

            else if (nums[mid] > target) r = mid;

            else l = mid;*/

            if (nums[mid] > target || (lower && nums[mid] >= target)) r = mid - 1, sta = mid;

            else l = mid + 1;
        }

        lower = false, l = 0, r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] > target || (lower && nums[mid] >= target)) r = mid - 1, end = mid;

            else l = mid + 1;
        }

        end -= 1;

        //cout << sta << ' ' << end << endl;

        if (sta <= end && end < nums.size() && nums[sta] == target && nums[end] == target) return vector<int>{sta, end};

        return vector<int>{-1, -1};
    }
};
// @lc code=end

