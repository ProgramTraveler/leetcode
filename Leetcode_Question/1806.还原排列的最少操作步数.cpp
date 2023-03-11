/*
 * @lc app=leetcode.cn id=1806 lang=cpp
 *
 * [1806] 还原排列的最少操作步数
 */

// @lc code=start
class Solution {
public:
    int reinitializePermutation(int n) { // 指针的问题真是麻烦 还有对容器的初始化
        vector<int> perm(n), target(n);

        int res = 0;

        iota(perm.begin(), perm.end(), 0);
        iota(target.begin(), target.end(), 0);

        //for (int i = 0; i < n; i ++) cout << perm[i] << " " << arr[i] << " " << target[i] << endl;

        while (true) { // 直接模拟
            vector<int> arr(n);

            for (int i = 0; i < n; i ++) {
                if (i % 2 == 0) arr[i] = perm[i / 2];

                else arr[i] = perm[n / 2 + (i - 1) / 2];
                
            }

            perm = move(arr);

            res ++;

            if ((perm == target)) break; // 进了不执行是几个意思
        }

        return res;
    }
};
// @lc code=end

