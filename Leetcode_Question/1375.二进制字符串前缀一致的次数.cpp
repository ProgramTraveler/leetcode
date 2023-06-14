/*
 * @lc app=leetcode.cn id=1375 lang=cpp
 *
 * [1375] 二进制字符串前缀一致的次数
 */

// @lc code=start
/*class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        // 记录 零 的最小位置的下标
        // 关键是 怎么维持 零 的最小位置下标 -> 动态更新？ 每次 sort 感觉太费时
        // 考虑一首 set?
        // 时间复杂度还是太高了
        int res = 0;

        set<int> idx;

        for (int i = 0; i < flips.size(); i ++) idx.insert(flips[i]);

        for (int i = 0; i < flips.size(); i ++) {
            idx.erase(flips[i]);

            if (i + 1 < *idx.begin()) res ++;
            
        }

        return res + 1; // 总会成功一次
    }
};*/

class Solution {
public:
    int numTimesAllBlue(vector<int> &flips) {
        int ans = 0, mx = 0, n = flips.size();
        for (int i = 0; i < n; i++) {
            mx = max(mx, flips[i]);
            ans += mx == i + 1;
        }
        return ans;
    }
};
// @lc code=end

