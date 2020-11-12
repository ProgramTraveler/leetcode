/*
 * @lc app=leetcode.cn id=922 lang=cpp
 *
 * [922] 按奇偶排序数组 II
 */

// @lc code=start
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        //保存数组中的奇数
        stack<int>odd;
        //保存数组中的偶数
        stack<int>even;
        //保存排序后的数组
        vector<int> ans;
        for(int i=0;i<A.size();i++){
            if(A[i]%2==0 || A[i]==0){
                even.push(A[i]);
            }else{
                odd.push(A[i]);
            }
        }
        for(int i=0;i<A.size();i++){
            if(i%2==0 || i==0){
                ans.push_back(even.top());
                even.pop();
            }else{
                ans.push_back(odd.top());
                odd.pop();
            }
        }
        return ans;
    }
};
// @lc code=end

