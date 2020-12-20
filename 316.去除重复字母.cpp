/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 */

// @lc code=start
class Solution {
public:
   class Solution {
public:
    string removeDuplicateLetters(string s) {
        //记录s中的字母个数
        vector<int> num(26);
        //记录字母剩余个数
        vector<int> sur(26);
        //遍历s字符串，记录其中的字母个数
        for (char x : s)
            num[x - 'a'] ++;
        //保存最终结果
        string str;
        //开始对s字符串进行处理
    
        for (char x : s) {
            if (! sur[x - 'a']) {
                while (! str.empty() && str.back() > x) {
                    if (num[str.back() -'a'] > 0) {
                        sur[str.back() - 'a'] = 0;
                        str.pop_back();
                    }else break;
                }
                sur[x - 'a'] = 1;
                str.push_back(x);
            }
            
            num[x - 'a'] -= 1;
        }
        return str;   
    }
};



// @lc code=end

