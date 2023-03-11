/*
 * @lc app=leetcode.cn id=1805 lang=cpp
 *
 * [1805] 字符串中不同整数的数目
 */

// @lc code=start
class Solution {
public:
    int numDifferentIntegers(string word) { // 不要尝试讲字符串中的数字装换为整数 后面的整数会造成整数溢出
        unordered_set<string> st;

        int n = word.size(), l = 0, r = 0; // 双指针

        while (true) {
            while (l < n && !isdigit(word[l])) l ++; // 找出第一个数字的位置

            if (l == n) break;

            r = l;

            while (r < n && isdigit(word[r])) r ++; // 找出数字后第一个字母的位置

            while (word[l] == '0' && r - l > 1) l ++; // 去除前导 0

            st.insert(word.substr(l, r - l));

            l = r;
        }

        return st.size();
        
    }
};
// @lc code=end

