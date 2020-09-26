/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        vector<int> ans;
        if(matrix.empty()) return ans; 
        int U=0; //定义上边界
        int D=matrix.size()-1; //定义下边界
        int L=0; //定义左边界
        int R=matrix[0].size()-1; //定义右边界
       
        while(true)
        {
            for(int i=L;i<=R;i++) ans.push_back(matrix[U][i]); //向右

            if(U+1>D) break; //做向下的检查，如果上边界继续向下移动就会超过下边界说明已经遍历完成
            U=U+1; //否则上边界就向下移动

            for(int i=U;i<=D;i++) ans.push_back(matrix[i][R]); //向下

            if(R-1<L) break; //判断右边界是否会突破左边界
            R=R-1; //否则就向左移动

            for(int i=R;i>=L;i--) ans.push_back(matrix[D][i]); //向右

            if(D-1<U) break; //判断下边界是否会突破上边界
            D=D-1; //否则就向上移动

            for(int i=D;i>=U;i--) ans.push_back(matrix[i][L]); //向左

            if(L+1>R) break; //判断左边界是否会突破右边界
            L=L+1; //否则就向右移动
        }
        return ans;
    }
};
// @lc code=end

