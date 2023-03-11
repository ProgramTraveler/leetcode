/*
 * @lc app=leetcode.cn id=771 lang=cpp
 *
 * [771] 宝石与石头
 */

// @lc code=start
class Solution {
public:
    int numJewelsInStones(string J, string S) 
    {
        int count=0;
        for(int i=0;i<J.size();i++)
        {
            //cout<<J[i]<<endl;
            for(int j=0;j<S.size();j++)
            {
                //cout<<"S:"<<S[j]<<"   ";
                if(J[i]==S[j])
                {
                    count++;
                    cout<<"C:"<<count<<endl;
                }
            }
            cout<<endl;
        }
        return count;
    }
};
// @lc code=end

