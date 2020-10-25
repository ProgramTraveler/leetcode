/*
 * @lc app=leetcode.cn id=845 lang=cpp
 *
 * [845] 数组中的最长山脉
 */

// @lc code=start
class Solution {
public:
    int longestMountain(vector<int>& A) {
        int ans=0; //记录山脉的个数
        if(A.size()<3) return 0; //如果山脉的个数小于3，说明不能构成山脉
        
        for(int i=1;i<A.size()-1;i++){
            int left=i;
            int right=i;
            int temp=1; //记录临时的山脉个数
            //如果当前的山峰左边和右边都比它小，说明有构成山脉的前提
            if(A[i]>A[i-1] && A[i]>A[i+1]){
                //开会判断它的最长山脉的长度
                 while(left>=1 || right<A.size()-1){
                    /*if((left>=1 && A[left]>A[left-1]) && (right<A.size()-1 && A[right]>A[right+1])){ //想直接在一个判断里完成，但对边界的处理不好操控
                        left--;
                        temp++;
                        right++;
                        temp++;
                    }else break;*/
                    //首先判断往左能到多远
                    if(left>=1 && A[left]>A[left-1]){
                        left--;
                        temp++;
                    }else if(right<A.size()-1 && A[right]>A[right+1]){ //再判断向右能到达多远
                        right++;
                        temp++;
                    }else break;
                }
            }
            //只有当长度大于等于3时，说明能构成山脉，此时更新山脉的长度
            ans=temp>=3 ? ans=max(ans,temp):ans;
        }
        //返回最长的山脉长度
        return ans;

    }
};
// @lc code=end

