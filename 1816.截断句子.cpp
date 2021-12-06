/*
 * @lc app=leetcode.cn id=1816 lang=cpp
 *
 * [1816] 截断句子
 */

// @lc code=start
class Solution {
public:
    string truncateSentence(string s, int k) {
        string temp = "";
        vector<string> res;
        for (int i = 0; i < s.size(); i ++) {
            if (s[i] != ' ') {
                temp += s[i];
            }else {
                //cout<< temp << endl;
                res.push_back(temp);
                temp = "";
            }
        }
        res.push_back(temp);
        temp = "";
        for (int i = 0; i < k - 1; i ++) {
            temp += res[i];
            temp += ' ';
        }
        temp = temp + res[k - 1];
        return temp;
    }
};
// @lc code=end

