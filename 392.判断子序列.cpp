/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution 
{
public:
    bool isSubsequence(string s, string t) 
    {
        int m=0;
        int n=0;
        int count=0;
        for(int i=m;i<t.size();i++)
        {
            for(int j=n;j<s.size();j++)
            {
                if(s[j]==t[i])
                    {
                        m++;
                        n++;
                        count++;
                        break;
                    }
                    else
                        break;
            }
        }
        if(count==s.size())
            return true;
        else
            return false;
    }
};
// @lc code=end

