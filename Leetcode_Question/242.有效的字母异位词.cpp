/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        /*if(s.size()!=t.size()) return false;
        //使用sort排序太慢了
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        for(int i=0;i<s.size();i++){
            if(s[i]==t[i]) continue;
            else return false;
        }
        return true;*/
        //换种方法
        //如果两个字符串的长度不一样，直接返回false
       if (s.size() != t.size()) return false;
        int aps[26] = {0}, apt[26] = {0};
        for (int i = 0; i < s.size(); i ++)
            aps[s[i] - 'a'] ++;
        for (int i = 0; i < t.size(); i ++)
            apt[t[i] - 'a'] ++;
        for (int i = 0; i < 26; i ++) {
            if (aps[i] == apt[i]) continue;
            else return false;
        }
        return true;
    }
};
// @lc code=end

