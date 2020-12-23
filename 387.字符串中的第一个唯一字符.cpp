/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

// @lc code=start
class Solution {
public:
    int firstUniqChar(string s) {
        //设置一个数组；来记录子母个数
        int ans[26] = {0};
        //遍历字符串，记录字幕出现的个数
        for (int i = 0; i < s.size(); i ++) 
            ans[s[i] - 'a'] ++;
        //创新遍历，如果有个数为1，直接返回结果
        for (int i = 0; i < s.size(); i ++) {
            if (ans[s[i] - 'a'] == 1) return i;
        }
        //没有返回-1
        return -1;
    }
};
// @lc code=end

