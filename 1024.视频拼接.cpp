/*
 * @lc app=leetcode.cn id=1024 lang=cpp
 *
 * [1024] 视频拼接
 */

// @lc code=start
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        //进行排序，方便遍历
        sort(clips.begin(),clips.end());
        //如果第一个数字不是0，说明肯定不能符合条件，直接返回-1
        if(clips[0][0]!=0) return -1;
        
        int res=0; //记录片段的次数
        int curEnd=0; //记录上一段的后面的片段
        int index=0; //下标
        //遍历
        while(index<clips.size()){
            //cout<<"A:"<<index<<endl;
            int MaxNum=0; //记录所遍历的片段中的最大的值
            bool find=false; //初始为没找到
            //查找满足条件的时间段
            while(index<clips.size() && clips[index][0]<=curEnd){
                //如果满足能够合成时间段，更新最大的时间
                if(clips[index][1]>curEnd){
                    MaxNum=max(MaxNum,clips[index][1]);
                    find=true;
                }
                
                index++;
            }
            //如果没有找到，直接返回-1
            if(!find) return -1;
            //要是能构成时间段，判断是否满足条件
            else{
                res++;
                curEnd=MaxNum; //更新curEnd
                //满足条件直接返回
                if(curEnd>=T) return res;
            }
        }
        return -1;
    }
};
// @lc code=end

