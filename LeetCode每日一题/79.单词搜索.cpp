/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
public: 
    bool DFS(vector<vector<char>>& board,string word,int i,int j,int num)
    {
        bool ans=false;
        if(board[i][j]!=word[num]) return false;
        if(num==word.size()-1) return true;
        char tem=board[i][j]; //存储当前值，方便后面的还原
        board[i][j]='0'; //为了防止走回头路
        //看上下左右是否有满足条件的点
        if(i+1<board.size())
        {
            ans=DFS(board,word,i+1,j,num+1);
            if(ans) return true;
        }
        if(i-1>=0)
        {
            ans=DFS(board,word,i-1,j,num+1);
            if(ans) return true;
        }
        if(j+1<board[0].size())
        {
            ans=DFS(board,word,i,j+1,num+1);
            if(ans) return true;
        }
        if(j-1>=0)
        {
            ans=DFS(board,word,i,j-1,num+1);
            if(ans) return true;
        }
        //还原，并返回当前值        
        board[i][j]=tem;
        return ans;
        
    }
    bool exist(vector<vector<char>>& board, string word) 
    {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                bool ans=DFS(board,word,i,j,0);
                if(ans) return true;
            }
        }
        return false;





        //本来想试试暴力搜索（就是把每个word的值在board里扫一遍）的方法来AC，直到遇到[["a","b"]["c","d"]]的实例，发现它只能在前一个点的基础上往相邻的地点走，还是没把题目分析清楚，这个就直接pass掉

        /*int len=0;
        int w_len=word.length();
        int num=0;
        //cout<<w_len;
        //int n=0;
        for(int i=0;i<board.size();i++)
        {
            cout<<word[num]<<endl;
            cout<<"I:"<<i<<endl;
            for(int j=0;j<board[i].size();j++)
            {
                cout<<"J:"<<j<<" ";
                if(board[i][j]==word[num])
                {
                    board[i][j]='0'; //把找到的值标记，防止重复
                    len++;
                    num++;
                    i=-1; //重置i的值，让i开始从头扫
                    //word=word.substr(1);
                    //cout<<word[0]<<endl;
                    //n=0;
                    //i=-1;
                    break;
                }
                else continue;
            }
        }
        cout<<len;
        //cout<<endl;
       // cout<<word.size();
        cout<<w_len;
        if(len==w_len) return true;
        else return false;*/    
    }
};// @lc code=end

