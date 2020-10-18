/*
 * @lc app=leetcode.cn id=5543 lang=cpp
 *
 * [5543] 两个相同字符之间的最长子字符串
 */

// @lc code=start
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int first=0; //首指针
        int last=s.size()-1; //尾指针
        int ans=INT_MIN; //记录最大值
        //通过尾部对首部的匹配，找出相同的两头，计算之间的值
        for(int i=first;i<s.size();i++){
            //从末尾开始匹配
            for(int j=last;j>i;j--){
                if(s[i]!=s[j]) continue;
                else {
                    //保存最大值
                    ans=max(ans,j-i-1);
                    break;
                }
            }
            
        }
        if(ans>=0) return ans;
        else return -1;

    }
};
// @lc code=end

