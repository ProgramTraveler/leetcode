/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 */

// @lc code=start
class Solution {
public:
    char findTheDifference(string s, string t) {
        //对字符串进行排序
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        //记录字符的下标
        int num=0;
        //开始同时对两个字符串进行比较
        while(num<s.size()){
            //如果是相等字符，继续向后比较
            if(s[num]==t[num]){
                num++;
            }else{
                //如果不相等，直接返回不相等的字符，也就是t的字符
                return t[num];
            }
        }
        //如果前面的都相等，说明字符肯定是最后一个不一样，直接返回就最后一个字符
        return t[num];
    }
};
// @lc code=end

