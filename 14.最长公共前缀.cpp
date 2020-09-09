/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        if(strs.empty()) return ""; //特殊情况提前考虑，在这之前不要进行操作
        string ans=strs[0]; //保存第一个字符串为比较对象
        for(int i=1;i<strs.size();i++)
        {
            for(int j=0;j<ans.length();j++)
            {
                if(ans[j]==strs[i][j]) continue;
                else
                {
                    ans.erase(j); //发现在j位置不一样了，则在j位置之后的（包括j位置）都删除掉
                    break;
                }
            }
        }
        
        return ans;
    }
};
// @lc code=end

