/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
       map<int,int> count; //使用map来记录
       //依次记录0,1,2的个数
       for(int i=0;i<nums.size();i++){
           count[nums[i]]++;
       }
       //将原数组清空
       nums.clear();
       //开始从0向数组存数
       int num=0;
       while(num<=2){
           //如果这个数的个数为0，说明已经存完了，开始去存下一个数
           if(count[num]==0) num++;
           else{
               //没存完就继续存
               nums.push_back(num);
               //个数减一
               count[num]--;
           }
       }
    }
};
// @lc code=end

