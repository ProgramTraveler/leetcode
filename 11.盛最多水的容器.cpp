/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height)
    {
        //本来知道用双指针（莫名其妙写成暴力算法了），想的还是没有官方细节
        int Max_vol=0; //记录最终的最大的那个容积
        int last=height.size()-1; //记录最后一条边的坐标
        int start=0; //最开始的边的坐标
        while(start!=last) //开始从两边向中间扫描（当start==last的时候说明扫描完成）
        {
            int tem_Max_vol=(last-start)*min(height[last],height[start]); //存储当前临时的这个容积
            Max_vol=max(Max_vol,tem_Max_vol); //把存储最终答案的容积与当前这个容积做比较（保存大的）
            //始终移动最小的那条边
            if(height[last]>height[start]) start++; 
            else last--;
        }
        return Max_vol;
        //完美超时（把当前垂线的前面所有组合求出来，比较最大的，算是个暴力），pass掉
        /*
        int Max_vol=0;
        for(int last=0;last<height.size();last++)
        {
            for(int start=0;start<last;start++)
            {
                int tem_Max_vol=(last-start)*min(height[last],height[start]);
                //cout<<"tem:"<<tem_Max_vol<<" ";
                Max_vol=max(Max_vol,tem_Max_vol);
                //cout<<"MAX:"<<Max_vol<<endl;
            }
        }
        return Max_vol;*/
    }
};
// @lc code=end

