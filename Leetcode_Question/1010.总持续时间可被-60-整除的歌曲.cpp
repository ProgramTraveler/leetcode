/*
 * @lc app=leetcode.cn id=1010 lang=cpp
 *
 * [1010] 总持续时间可被 60 整除的歌曲
 */

// @lc code=start
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int res =  0, cnt[60]{};

        for (auto t : time) {
            res += cnt[(60 - t % 60) % 60]; // 之所以 () % 60 是为了处理 t % 60 为 0 的情况

            cnt[t % 60] ++;
        }

        return res;

        /* 不出意外的超时
        int res = 0, cnt = 0;

        int n = time.size();

        for (int i = 0; i < n; i ++) {

            cnt = time[i];

            for (int j = i + 1; j < n; j ++) {
                cnt += time[j];

                if (cnt % 60 == 0) res ++;

                cnt -= time[j];
            }
        }*/
    }
};
// @lc code=end

