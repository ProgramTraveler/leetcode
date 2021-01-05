/*
 * @lc app=leetcode.cn id=830 lang=cpp
 *
 * [830] 较大分组的位置
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        //记录最后的答案
        vector<vector<int>> ans;
        //记录相同字母出现的个数
        int count = 1;
        //遍历字符串
        for (int i = 0; i < s.size(); i ++) {
            //如果当前为最后一个字符或者当前的字符和下一个字符不一样
            if (i == s.size() - 1 || s[i] != s[i + 1]) {
                //如果当前的字符数大于等于3
                if (count >= 3) {
                    //将位置的下标记录在ans中
                    ans.push_back({i - count + 1,i});
                }
                //将记录的个数重置
                count = 1;
            }else {
                //这个字符的个数加一
                count ++;
            }
        }
        //返回最终的结果
        return ans;
    }
};
// @lc code=end

