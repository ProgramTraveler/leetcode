/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
class Solution {
public:
    void DFS(vector<vector<char>>& board,int num)
    {
        if(num==space.size()) //当所有的空格被填满后就结束
        {
            answer=board;
            return;
        }
        pair<int,int> tem=space[num]; //定义一个新的pair型（后来才知道可以auto[i,j]=space[num]）
        int i=tem.first; // 获取空格的行数
        int j=tem.second; //获取空格的列数
        //auto [i,j]=space[num];
        for(int data=0;data<9;data++)
        {
            if(!line[i][data] && !column[j][data] && !block[i/3][j/3][data]) //如果没被使用过
            {
                board[i][j]=data+'0'+1; //赋值
                line[i][data]=true; //标记
                column[j][data]=true;
                block[i/3][j/3][data]=true;
                //递归
                DFS(board,num+1);
                //回溯
                board[i][j]='.';
                //重新标记
                line[i][data]=false;
                column[j][data]=false;
                block[i/3][j/3][data]=false;
                //board[i][j]='.';
            }
        }
    }

    void solveSudoku(vector<vector<char>>& board) 
    {
        //memset(s,ch,n) 将s的前n个字节替换为ch
        memset(line,false,sizeof(line)); 
        memset(column,false,sizeof(column));
        memset(block,false,sizeof(block));
        
        //把数独表全部遍历一遍
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                //如果遇到空格，就保存它的行数和列数
                if(board[i][j]=='.') 
                {
                    space.emplace_back(i,j);
                }
                else
                {
                    //如果使用了，记录它的行数和列数，以及它的九宫格信息
                    int data=board[i][j]-'0'-1;
                    line[i][data]=true;
                    column[j][data]=true;
                    block[i/3][j/3][data]=true;
                }
            }
        }
        DFS(board,0);
        board=answer;
    }
private:
    bool line[9][9];  //记录在第i行的数字是否使用过的
    bool column[9][9]; //记录在第j列的数字是否使用过
    bool block[3][3][9];//记录在九宫格里的数字是否使用过
    vector<pair<int,int>> space;  //pair类型是将两个数据合成一组数据
    vector<vector<char>> answer; //记录回溯后的九宫格
};
// @lc code=end

