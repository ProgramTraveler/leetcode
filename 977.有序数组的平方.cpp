/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        /*这个方法很容易想到
        vector<int> ans; //记录答案

        //通过遍历，把每个数的平方值存入数组
        for(int i=0;i<A.size();i++){
            int temp=A[i]*A[i];
            ans.push_back(temp);
        }
        //对最终的数组进行排序
        sort(ans.begin(),ans.end());
        return ans;
        */

        //双指针
        vector<int> ans(A.size(),0);

        int first=0; //头指针
        int last=A.size()-1; //尾指针
        int pos=A.size()-1; //记录数组下标
        //从头和尾遍历
        while(first<=last && pos>=0){
            //如果尾的数比头的数大，把大的数记录
            if(A[first]*A[first]>A[last]*A[last]){

                ans[pos]=(A[first]*A[first]);
                
                //更新头指针
                first++;
            }
            else{
                ans[pos]=(A[last]*A[last]);
                
                //更新尾指针
                last--;
            }
            //更新数组的下标
            pos--;
        }
        return ans;


    }
};
// @lc code=end

