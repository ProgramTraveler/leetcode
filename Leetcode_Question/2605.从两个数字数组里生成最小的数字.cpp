class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int res = 0;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int n1 = min(nums1[0], nums2[0]);

        int n2 = max(nums1[0], nums2[0]);

        res = n1 * 10 + n2;

        unordered_map<int, int> cnt;

        for (int i = 0; i < nums1.size(); i ++) cnt[nums1[i]] ++;

        for (int i = 0; i < nums2.size(); i ++) cnt[nums2[i]] ++;

        for (auto [k, v] : cnt) if (v > 1) res = min(res, k);

        return res;
    }
};