/*
 * @lc app=leetcode.cn id=1046 lang=cpp
 *
 * [1046] 最后一块石头的重量
 */

// @lc code=start
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        //对数组的数据进行遍历
        while(stones.size()>1){
            //每次对更新后的数组进行排序（这样的话每次重量最大的石头都在最后两位）
            sort(stones.begin(),stones.end());
            //获得重量最大和重量第二大的石头下标
            int last1=stones.size()-1;
            int last2=stones.size()-2;
            //把已经粉碎的石头踢出原数组（一共两块石头）
            stones.pop_back();
            stones.pop_back();
            //在把粉碎后的剩下的石头重量存入数组
            stones.push_back(abs(stones[last1]-stones[last2]));
        }
        return stones[0];     
    }
};
// @lc code=end

