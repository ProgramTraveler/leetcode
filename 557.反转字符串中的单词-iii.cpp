/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 */

// @lc code=start
class Solution
{
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = 0;
        while (i < n) {
            int start = i;//每个子字符串的起始下标
            while (i < n && s[i] != ' ')
                i++;
            int end = i - 1;//每个子字符串的结束下标
            while (start < end) {
                swap(s[start], s[end]);//不断头尾交换以实现翻转
                start++;
                end--;
            }
            while (i < n && s[i] == ' ')
                i++;
        }
        return s;
    }
};
// @lc code=end

