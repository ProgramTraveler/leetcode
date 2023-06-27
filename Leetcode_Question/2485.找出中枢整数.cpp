class Solution {
public:
    int pivotInteger(int n) {
        // 前缀和
        vector<int> f(n + 1, 0);

        f[0] = 0;

        for (int i = 1; i < f.size(); i ++) f[i] = f[i - 1] + i;

        int res = -1, idx = f.size() - 1;

        /*for (int i = 1; i < f.size(); i ++) {
            if (f[i] == f[idx] - f[i] + i) {
                res = i;

                break;
            }
        }*/

        // 其实可以试试二分 在本题效果好像不大
        int l = 0, r = f.size();

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (f[mid] < f[idx] - f[mid] + mid) l ++;

            if (f[mid] > f[idx] - f[mid] + mid) r --;

            if (f[mid] == f[idx] - f[mid] + mid) {
                res = mid;

                break;
            }
        }

        return res;
    }
};