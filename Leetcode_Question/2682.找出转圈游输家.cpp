class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        unordered_map<int, int> cnt; // i 朋友的接球次数

        int i = 1;
        int idx = 0; // 当前位置的小孩 为了方便取模运算 从 0 开始

        while (1) {
            cnt[idx] ++;

            if (cnt[idx] >= 2) break;

            idx = (i * k + idx) % n; // 传递给下一个小孩
            i ++;
        }

        vector<int> res;

        for (int i = 0; i < n; i ++) {
            if (cnt[i] == 0) res.emplace_back(i + 1);
        }

        return res;
    }
};