class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        // 长度为偶数
        // 排序
        set<int> cnt;

        // 其实不用求平均值 只要和相同就行

        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;

        while (l < r) {
            // cout << l + r << endl;
            cnt.insert(nums[l] + nums[r]);

            l ++, r --;
        }

        return cnt.size();
    }
};