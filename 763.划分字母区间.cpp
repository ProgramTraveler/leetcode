/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string S) 
    {
        int num = S.length();
        unordered_map<int,int> Map;
        vector<int> answer;
        for(int i = 0; i < num; i++)
        {
            Map[S[i] - 'a'] = i;
        }
        int i = 0;
        while(i < num){
            int flag = Map[S[i] - 'a'];
            for(int j = i + 1; j < flag; j++)
            {
                flag = max(flag, Map[S[j] - 'a']);
            }
            answer.push_back(flag - i + 1);
            i = flag + 1;
        }
        return answer;
    }
};
// @lc code=end

