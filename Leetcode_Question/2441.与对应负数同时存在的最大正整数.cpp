class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int l = 0, r = nums.size() - 1;

        while (l < r) {
            if (nums[l] < 0 && nums[r] > 0 && abs(nums[l]) == nums[r]) return nums[r];

            if (nums[l] < 0 && nums[r] > 0 && abs(nums[l]) < nums[r]) r --;

            if (nums[l] < 0 && nums[r] > 0 && abs(nums[l]) > nums[r]) l ++;

            if (nums[l] > 0 || nums[r] < 0) break;
        }

        return -1;
    }
};