class Solution {
public:
    int hIndex(vector<int>& cit) {
        // 这不二分？
        int n = cit.size();

        int l = 1, r = n;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (cit[n - mid] >= mid) l = mid + 1;
            else r = mid - 1;
        }

        return r;
    }
};