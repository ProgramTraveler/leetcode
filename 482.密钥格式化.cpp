/*
 * @lc app=leetcode.cn id=482 lang=cpp
 *
 * [482] 密钥格式化
 */

// @lc code=start
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string res;
        int index = 0;
        for (int i = s.size() - 1; i >= 0; i --) {
            if (s[i] != '-') {
                res.push_back(toupper(s[i])); //将小写字母变成大写字母
                index ++;
                if (index % k == 0) { //当达到k个的时候，插入'-'
                    res.push_back('-');
                }
            }
        }
        //cout<<res<<endl;
        if (res.back() == '-') res.pop_back(); //去掉前面多余的'-'
        reverse(res.begin(), res.end()); //倒置
        return res;
    }
};
// @lc code=end

