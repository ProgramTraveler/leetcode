/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    //构建出一个电话按键
    map<char, string> M = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},
        {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };
    vector<string> ans; //储存最终的答案
    string interim_ans; //储存临时的答案

    //将按键的字母循环匹配
    void DFS(int index,string digits)
    {
        if(index==digits.length())
        {
            ans.push_back(interim_ans);
            return;
        }
        else
        {
            for(int i=0;i<M[digits[index]].length();i++)
            {
                interim_ans.push_back(M[digits[index]][i]);
                DFS(index+1,digits);
                interim_ans.pop_back(); //回溯还原为上一步（ab->a）
            }
        }
    }
    vector<string> letterCombinations(string digits) 
    {
        if(digits.length()==0)
        {
            return ans;
        }
        else
        {
            DFS(0,digits);
            return ans;
        }
    }
};
// @lc code=end

