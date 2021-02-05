/*
 * @lc app=leetcode.cn id=1208 lang=cpp
 *
 * [1208] 尽可能使字符串相等
 */

// @lc code=start
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int res = INT_MIN; //记录最终的结果
        int sum = 0; //记录转换消耗的总和
        int left = 0, right = 0; //左右指针
        vector<int> cost(s.size(), 0); //保存两个字符串变换需要的消耗
        //记录两个字符串的消耗
        for (int i = 0; i < s.size(); i ++) 
            cost[i] = (abs(s[i] - t[i]));
        //滑动窗口
        while (right < s.size()) {
            sum += cost[right]; //保存交换的消耗
            //当消耗超过预设值
            while (sum > maxCost) {
                //收缩窗口
                sum -= cost[left];
                left ++;
            }
            //更新最长的字符串
            res = max(res, right - left + 1);
            right ++;
        }
        //返回结果
        return res;
    }
};
// @lc code=end

