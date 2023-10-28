class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        long long f1 = 1e4;
        long long f2 = 1e9;

        long long vol = 1L * length * width * height;

        vector<string> res = {"Bulky", "Heavy", "Both", "Neither"};

        vector<int> cnt(4, 0);

        int idx = 0;

        if (mass >= 100) cnt[1] = 1;

        if (length >= f1 || width >= f1 || height >= f1 || mass >= f1) cnt[0] = 1;

        if (vol >= f2) cnt[0] = 1;

        int sum = accumulate(cnt.begin(), cnt.end(), 0);

        idx = 3;

        if (sum == 2) idx = 2;

        if (sum == 1 && cnt[0] == 1) idx = 0;
        if (sum == 1 && cnt[1] == 1) idx = 1;

        return res[idx];
    }
};