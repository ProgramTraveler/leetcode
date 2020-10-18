/*
 * @lc app=leetcode.cn id=1614 lang=cpp
 *
 * [1614] 括号的最大嵌套深度
 */

// @lc code=start
class Solution {
public:
    int maxDepth(string s) {
        //遇到左括号就++，遇到右括号就--
        int ans=0;
        int temp=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==')'){
                temp--;
            }else if(s[i]=='('){
                //ans=max(ans,temp);
                temp++;
            }else ans=max(ans,temp); 
        }
        return ans;


    }
};
// @lc code=end

