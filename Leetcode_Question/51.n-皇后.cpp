/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
//n皇后问题，回溯的经典题型
class Solution {
public:
    void backtrak(int n,int row,vector<string> &board, vector<vector<string>> &answer )
    {
        //row为行，col为列

        if(row==n) //终止条件
        {
            answer.push_back(board); //存放结果
            return;
        }
        //枚举同一个位置的所有可能性
        for(int col=0;col<n;col++)
        {
            if(cheak(row,col,board,n))
            {
                //递归处理节点
                board[row][col]='Q';
                backtrak(n,row+1,board,answer);
                //回溯，撤销处理结果
                board[row][col]='.';
            }
        }
    }
    bool cheak(int row,int col,vector<string> &board,int n)
    {
        //检查列
        for(int i=0;i<row;i++)
        {
            if(board[i][col]=='Q') return false;
        }
        //检查左对角线
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--)
        {
            if(board[i][j]=='Q') return false;
        }
        //检查右对角线
        for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++)
        {
            if(board[i][j]=='Q') return false;
        }
        return true;
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<string> board(n,string(n,'.'));  //开出一个棋盘
        vector<vector<string>> answer;  //存储最后的结果

        backtrak(n,0,board,answer); 
        return answer;
        
    }
};// @lc code=end

