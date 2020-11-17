/*
 * @lc app=leetcode.cn id=1030 lang=cpp
 *
 * [1030] 距离顺序排列矩阵单元格
 */

// @lc code=start
class Solution {
public:
    int distance(int r0,int c0,int r1,int c1){
       return abs(r0-r1)+abs(c0-c1);
    }
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        //记录最终的的排序结果
        vector<vector<int>>ans;
        //获得与点最远的那个距离
        int MaxD=max(r0,R-1-r0)+max(c0,C-1-c0);
        //定义一个桶，来记录与给定点的距离和这个点的坐标
        vector<vector<vector<int>>>bucket(MaxD+1);
        //遍历这个图的所有点   
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                //获得该点和给定点的曼哈顿距离
                int d=distance(r0,c0,i,j);
                //将坐标存进临时数组
                vector<int>temp={i , j};
                //将该位置对应的的坐标点存入桶中
                bucket[d].push_back(move(temp));
            }
        }
        //对桶开始遍历
        for(int i=0;i<=MaxD;i++){
            //将该距离的所有坐标遍历，存入ans中
            for(auto &it : bucket[i]){
                ans.push_back(it);
            }
        }
        //返回结果
        return ans;
    }
};

// @lc code=end

