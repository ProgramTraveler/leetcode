/*
 * @lc app=leetcode.cn id=1122 lang=cpp
 *
 * [1122] 数组的相对排序
 */

// @lc code=start
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int>ans; //记录出现在arr2中的数字
        sort(arr1.begin(),arr1.end());//因为题目要求最后不在arr2中的数字按升序排列。所以对arr1先排序
        //遍历arr2数组中的数字
        for(int i=0;i<arr2.size();i++){
            //遍历arr1中的数字
            for(int j=0;j<arr1.size();j++){
                //如果arr2中的数字和arr1中的数字一样
                if(arr2[i]==arr1[j]){
                    //将数字存入ans数组
                    ans.push_back(arr1[j]);
                    //将已经存入的数字进行标记，方便后面查找不在arr2中的数字
                    arr1[j]=-1;
                }else{
                    //temp.push_back(arr)
                    continue;
                    
                }
            }
        }
        //重新遍历arr1数组，查看没有被标记的数字
        for(int i=0;i<arr1.size();i++){
            //如果数字不是-1，说明没有被标记，就不在arr2中
            if(arr1[i]!=-1){
                //那么就将它存入ans数组末尾（因为arr1已经排序，最后这个遍历的数字一定就是升序的）
                ans.push_back(arr1[i]);
            }else{
                continue;
            }
        }
        return ans;
    }
};
// @lc code=end

