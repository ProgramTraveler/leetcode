/*
 * @lc app=leetcode.cn id=2208 lang=cpp
 *
 * [2208] 将数组和减半的最少操作次数
 */

// @lc code=start
class Solution {
public:
    int halveArray(vector<int>& nums) {
        // 贪心 每次都减少最大的
        // 但是每次都对最后的结果排序 一定会超时
        // 最大堆
        // priority_queue<double> pq(nums.begin(), nums.end());
        // int res = 0;

        // double sum = accumulate(nums.begin(), nums.end(), 0.0) / 2;

        // while (sum > 0) {
        //     double x = pq.top();

        //     pq.pop();

        //     sum -= x / 2;
        //     pq.push(x / 2);

        //     res ++;
        // }

        // return res;

        // 避免浮点数的写法
        int res = 0;
        
        priority_queue<long long> pq;

        long long half =  0;

        for (int i = 0; i < nums.size(); i ++) pq.push(nums[i] * pow(2, 20)), half += nums[i] * pow(2, 20);

        half /= 2;

        while (half > 0) {

            long long x = pq.top() / 2;

            half -= x;

            pq.pop();

            pq.push(x);

            res ++;
        }

        return res;
    }
};
// @lc code=end

