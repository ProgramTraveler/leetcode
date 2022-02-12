class Solution {
    public int minimumDifference(int[] nums, int k) {
        Arrays.sort(nums);
        int n = nums.length, ans = nums[k - 1] - nums[0]; 
        for (int i = k; i < n; i ++) {
            ans = Math.min(ans, nums[i] - nums[i - k  +1]);
        }
        return ans;
    }
}