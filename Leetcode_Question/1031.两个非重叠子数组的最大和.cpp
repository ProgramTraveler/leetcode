/*
 * @lc app=leetcode.cn id=1031 lang=cpp
 *
 * [1031] 两个非重叠子数组的最大和
 */

// @lc code=start
class Solution {
public:

    int maxSumTwoNoOverlap(vector<int> &nums, int firstLen, int secondLen) {
        int ans = 0, n = nums.size(), s[n + 1];
        s[0] = 0;
        partial_sum(nums.begin(), nums.end(), s + 1); // 计算 nums 的前缀和
        auto f = [&](int firstLen, int secondLen) {
            int maxSumA = 0;
            for (int i = firstLen + secondLen; i <= n; ++i) {
                maxSumA = max(maxSumA, s[i - secondLen] - s[i - secondLen - firstLen]);
                ans = max(ans, maxSumA + s[i] - s[i - secondLen]);
            }
        };
        f(firstLen, secondLen); // 左 a 右 b
        f(secondLen, firstLen); // 左 b 右 a
        return ans;
    }

    // int func1(vector<int>& nums, int len1, int len2) {
    //     int res_1 = 0, res_2 = 0; // 记录两个不同大小窗口的最大值

    //     vector<int> coor(2, 0); // 记录和最大的窗口区间
    //     int l = 0, r = 0; // 窗口区间
    //     int tem_sum = 0; // 临时值

    //     while (r < nums.size()) {
    //         tem_sum += nums[r];

    //         if ((r - l + 1) >= len1) { // 满足窗口大小

    //             if (tem_sum >= res_1) res_1 = tem_sum, coor[0] = l, coor[1] = r; // 如果和大于之前值 记录区间

    //             tem_sum = 0;

    //             r = l;
    //             l ++;
    //         }

    //         r ++;
    //     }

    //     l = 0, r = 0;
    //     tem_sum = 0;

    //     while (r < coor[0]) {
    //         tem_sum += nums[r];

    //         if ((r - l + 1) >= len2) {
            
    //             res_2 = max(res_2, tem_sum);

    //             tem_sum = 0;

    //             r = l, l ++;
    //         }       

    //         r ++;
    //     }       

    //     l = coor[1] + 1, r = l;
    //     tem_sum = 0;

    //     while (r < nums.size()) {       
    //         tem_sum += nums[r];     

    //         if ((r - l + 1) >= len2) {

    //             res_2 = max(tem_sum, res_2);        
    //             tem_sum = 0;        
    //             r = l, l ++;
    //         }       

    //         r ++;
    //     }
   
    //     cout << res_1 << " " << res_2 << endl;

    //     return res_1 + res_2;
        
    // }

    // int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {

    //     return max(func1(nums, firstLen, secondLen), func1(nums, secondLen, firstLen));
        
    // }
};
// @lc code=end

