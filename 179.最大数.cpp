/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start
class Solution {
public:
    string largestNumber(vector<int>& nums) 
    {
        vector<string> int2str;
        string res;
        for (int i : nums)          // 将数组中每个元素都转换成字符串
            int2str.push_back(to_string(i));
        sort(int2str.begin(), int2str.end(), [](string& a, string& b){return a + b > b + a;});
        if (int2str[0] == "0")  return "0"; // 检查前导0的特殊情况
        for (string s : int2str)    // 将排好序的字符串拼接起来即是结果
            res += s;
        return res;
    }
};
// @lc code=end

