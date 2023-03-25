/*
 * @lc app=leetcode.cn id=1574 lang=cpp
 *
 * [1574] 删除最短的子数组使剩余数组有序
 */

// @lc code=start
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        // 主要应该是找最长的 非递减序列

        int n = arr.size(), r = n - 1;

        while (r && arr[r - 1] <= arr[r]) r --;

        // 如果已经是非递减的了 直接返回 0
        if (r == 0) return 0;

        // 删除从 0 到 r - 1 的子集
        int res = r;

        for (int l = 0; l == 0 || arr[l - 1] <= arr[l]; l ++) {
            while (r < n && arr[r] < arr[l]) {
                r ++;
            }

            res = min(res, r - l - 1);
        }
        
        return res;

        /*
        // 正向遍历 反向遍历

        int res = 0;

        int l = 0, r = l + 1;

        while (r < arr.size()) {
            if (arr[l] > arr[r]) {
                res ++;

                r ++;
            } else {
                l ++, r ++;
            }
        }

        l = arr.size() - 1, r = l - 1;

        int cnt = 0;

        while (r >= 0) {
            if (arr[l] < arr[r]) {
                cnt ++;

                r --;
            } else {
                l --, r --;
            }
        }

        return min(res, cnt);*/
    }
};
// @lc code=end

