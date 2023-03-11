/*
 * @lc app=leetcode.cn id=1417 lang=cpp
 *
 * [1417] 重新格式化字符串
 */

// @lc code=start
class Solution {
public:
    string reformat(string s) {
        string ans; //返回最终的结果
        vector<char> res(s.size(), 'a');
        int num = 0, word = 0; //分别记录字符串中数字和字母出现的次数

        for (int i = 0; i < s.size(); i ++) {
            if (s[i] >= 48 && s[i] <= 57) num ++;
            else word ++;   
        }

        int index_num = 0, index_word = 0;

        if (abs(num - word) > 1) 
            return ""; 
        else if (num > word) {
            index_num = 0;
            index_word = 1;
        } else {
            index_num = 1;
            index_word = 0;
        }

        for (int i = 0; i < s.size(); i ++) {
            if (s[i] >= 48 && s[i] <= 57) { 
                res[index_num] = s[i];
                index_num += 2;
            }
            else {
                res[index_word] = s[i];
                index_word += 2;
            }   
        }

        for (int i = 0; i < s.size(); i ++) ans += res[i];
        
        return ans;

    }
};
// @lc code=end

