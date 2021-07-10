/*
 * @lc app=leetcode.cn id=1365 lang=cpp
 *
 * [1365] 有多少小于当前数字的数字
 */

// @lc code=start
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        //本来想着用排序，这样更简单，但看了一下返回的答案是有顺序的
        //sort(nums.begin(),nums.end());
        
        vector<int> ans;//记录每次遍历后的比当前数大的结果
        for(int i=0;i<nums.size();i++){
            int temp=0;//保存比当前数小的数的个数
            int left=i-1;//当前数的左边的数
            int right=i+1;//当前数的右边的数
            //向左查找
            while(left>=0){
                //如果左边的数比当前数小，temp++
                if(nums[i]>nums[left]) temp++;
                //继续向左移动
                left--;
            }
            //向右查找
            while(right<nums.size()){
                //如果右边的数比当前数小，temp++
                if(nums[i]>nums[right]) temp++;
                //继续向右移动
                right++;
            }
            //把比当前数小的个数存入数组
            ans.push_back(temp);
        }
        //返回最后的结果
        return ans;        

    }
};
// @lc code=end

