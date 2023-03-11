/*
 * @lc app=leetcode.cn id=1710 lang=cpp
 *
 * [1710] 卡车上的最大单元数
 */

// @lc code=start
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // 没什么说的 直接贪心即可
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int> &a, const vector<int> &b){return a[1] > b[1];}); // 对二维数组按照第二列从大到小排列

        int res = 0, idx = 0;

        while (truckSize) {
            if (boxTypes[idx][0] == 0) idx ++;

            if (idx >= boxTypes.size()) break; // 防止数组越界
            
            res += boxTypes[idx][1];

            boxTypes[idx][0] --;

            truckSize --;
            
        }

        return res;
    }
};
// @lc code=end

