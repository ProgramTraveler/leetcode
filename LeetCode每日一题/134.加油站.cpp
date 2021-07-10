/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int Gas=0;//总的汽油数量
        int Cost=0;//总的油耗数量
        //获得当前的总油量和总的油耗数
        for(int i=0;i<gas.size();i++){
            Gas+=gas[i];
            Cost+=cost[i];
        }
        //如果总的油耗比总的汽油多，直接返回-1
        if(Gas<Cost) return -1;
        //如果不是，则开始从头查找能够转一圈的出发点
        for(int i=0;i<gas.size();i++){
            //出发点的下标
            int temp=i;
            //余下的汽油
            int rest=0;
            //如果当前下标的汽油比消耗少，说明不能作为出发点，直接去寻找下一个点
            if(gas[i]<cost[i]) continue;
            //否则从当前点出发，判断是否能够循环一圈
            else{
                int flag=temp;
                bool pass=false;
                while(flag<gas.size()){
                    //跑去下一地点的油耗
                    rest+=gas[flag]-cost[flag];
                    //如果不能跑去下一地点，直接结束
                    if(rest<0) break;
                    //如果可以跑去下一地点
                    else{
                        //如果当前下标是最后一个，那么下一次的地点从0开始
                        if(flag==gas.size()-1){
                            //表示汽车已经从出发地点出发
                            pass=true;
                            //下一次从0开始
                            flag=0;
                        }else{
                            //汽车已经出出发地点出发
                            pass=true;
                            //开向下一地点
                            flag++;
                        }
                    }
                    //如果汽车已经是从出发地点出发过，而且已经回来了，返回出发的下标
                    if(pass=true && temp==flag){
                        return temp;
                    }
                }
            }
        }
        //如果没有的话，返回-1
        return -1;
    }
};
// @lc code=end

