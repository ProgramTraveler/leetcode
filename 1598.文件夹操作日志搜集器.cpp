/*
 * @lc app=leetcode.cn id=1598 lang=cpp
 *
 * [1598] 文件夹操作日志搜集器
 */

// @lc code=start
class Solution 
{
public:
    int minOperations(vector<string>& logs) 
    {
        int result = 0;
        int len = logs.size();
        for(int i = 0; i < len; i++)
        {
            if(logs[i] == "./")
                result += 0;
            else if(logs[i] == "../")
                result -= 1;
            else
                result += 1;
            if(result < 0)
                result = 0;
        }
        return result;
    }
};


// @lc code=end

