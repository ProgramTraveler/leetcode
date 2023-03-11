/*
 * @lc app=leetcode.cn id=659 lang=cpp
 *
 * [659] 分割数组为连续子序列
 */

// @lc code=start
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int>count;//记录数字的个数
        unordered_map<int,int>tail;//记录每个序列的最后一个数字
        //获得nums数组中的每个数字的个数
        for(auto nu:nums){
            count[nu]++;
        }
        //遍历count中的每个数字的个数
        for(auto nu:nums){
            //如果当前数字个数为0.说明这个数字已经被用完了，去找后面的那个数字
            if(count[nu]==0) continue;
            //如果当前的数字个数不为0，先看前面的数字是否被用，如果被用了，那么就加在它后面
            if(count[nu]>0 && tail[nu-1]>0){
                //当前数组的个数减一
                count[nu]--;
                //更新放数字的最后一位
                tail[nu-1]--;
                tail[nu]++;
            }else if(count[nu]>0 && count[nu+1] && count[nu+2]>0){
                //如果前面的那个数字没有被使用，那么就只能重新去开一组序列
                count[nu]--;
                count[nu+1]--;
                count[nu+2]--;
                //更新当前序列的最后一位数字
                tail[nu+2]++;
            }
            else return false;
        }
        return true;
    }
};
// @lc code=end

