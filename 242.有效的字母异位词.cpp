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
        if(s.size()!=t.size()) return false;
        //定义一个26个大小的数组，用来记录26个小写字母
        int num[26]={0};
        //比较s和t中的字母
        for(int i=0;i<s.size();i++){
            //将s中的字母对应的位置加一
            num[s[i]-'a']++;
            //将t中的字母对应的位置减一
            num[t[i]-'a']--;
        }
        //遍历num[]中的数字，观察是否为0
        for(int i=0;i<26;i++){
            //为0说明要么不存在，要么s和t中都有
            if(num[i]==0) continue;
            //不为0就直接返回false
            else return false;
        }
        //全部遍历完，都为0返回true
        return true;
    }
};
// @lc code=end

