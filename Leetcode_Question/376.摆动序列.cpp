/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<=1) return nums.size();
        int preDiff=0;//前一对峰值
        int curDiff=0;//当前的一对峰值
        int ans=1;//默认最右侧会有一个峰值
        for(int i=1;i<nums.size();i++){
            //计算出当前的峰值
            curDiff=nums[i]-nums[i-1];
            //如果满足条件
            if((curDiff<0 && preDiff>=0) || (curDiff>0 && preDiff<=0)){
                ans++;
                //当前峰值在下一次会变成前一个峰值
                preDiff=curDiff;
            }
        }
        return ans;

    }
};
// @lc code=end

