/*
 * @lc app=leetcode.cn id=1184 lang=cpp
 *
 * [1184] 公交站间的距离
 */

// @lc code=start
class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if (start > destination) { //如果 start 的值比 destintion 的值大，交换二者的值
            swap(start, destination);
        }

        return min(accumulate(distance.begin() + start, distance.begin() + destination, 0),
                   accumulate(distance.begin(), distance.begin() + start, 0) + accumulate(distance.begin() + destination, distance.end(), 0)); //计算顺时针和逆时针的下的不同的距离
    }
};
// @lc code=end

