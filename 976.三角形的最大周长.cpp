/*
 * @lc app=leetcode.cn id=976 lang=cpp
 *
 * [976] 三角形的最大周长
 */

// @lc code=start
class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        //如果数字中的数字个数比3小，说明不能构成三角形，返回0
        if(A.size()<3) return 0;
        //对数组进行排序
        sort(A.begin(),A.end());
        //从后向前进行，能构成最长的周转一定是相邻的三个数字，而且它们满足a+b>c
        for(int i=A.size()-1;i>=2;i--){
            //如果满足这个条件，就返回最长的周长
            if(A[i-1]+A[i-2]>A[i]) return A[i-1]+A[i-2]+A[i];
        }
        //没有能构成面积不为0的三角形的话，就返回0
        return 0;
    }
};
// @lc code=end

