/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class Solution {
public:
    int row=0; //列
    int line=0; //行
    void dfs(vector<vector<char>>& board,int l,int r)
    {
        if(l<0 || l>=line || r<0 || r>=row || board[l][r]!='O') //判断是否越界和边界是否有X
        {
            return;
        }
        else
        {
            board[l][r]='A';  //标记边界的O
            //向该标记的点的四周扩散，遍历是否有与该点相邻的O
            dfs(board,l+1,r); 
            dfs(board,l-1,r);
            dfs(board,l,r+1);
            dfs(board,l,r-1);
        }
    }
    void solve(vector<vector<char>>& board) 
    {
        line=board.size();
        if(line==0)   return; //如果输入的是一个空值，直接返回
        row=board[0].size();
        //if(line==0)   return;  //不知道为什么在这里返回就特么直接给我报错了，害的我特么看了半天逻辑，傻逼玩意
        for(int i=0;i<line;i++)
        {
            //按行遍历，查找边界O
            dfs(board,i,0);
            dfs(board,i,row-1);
        }
        for(int j=0;j<row;j++)
        {
            //按列遍历，查找边界O
            dfs(board,0,j);
            dfs(board,line-1,j);
        }
        //这就简单的循环，把标记的O变回来，把没标记的O变成X，当然，X不变
        for(int i=0;i<line;i++)
        {
            for(int j=0;j<row;j++)
            {
                if(board[i][j]=='A')
                {
                    board[i][j]='O';
                }
                else if(board[i][j]=='O' || board[i][j]=='X')
                {
                    board[i][j]='X';
                }
            }
        }
    }
};
// @lc code=end

