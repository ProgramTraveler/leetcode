class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        // 只要判断每个点的左右节点 记录和
        unordered_map<int, int> cnt;

        for (int i = 0; i < nums.size(); i ++) {
            //if (i - 1 >= 0) cnt[nums[i] + nums[i - 1]] ++;

            if (i + 1 < nums.size()) cnt[nums[i] + nums[i + 1]] ++; 
        }

        for (auto [k, v] : cnt) if (v > 1) return true;

        return false;
    }
};