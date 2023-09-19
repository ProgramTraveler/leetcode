/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        vector<int> dp(n + 1,0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < n - 1; i ++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        int result = dp[n - 2];
        dp[0] = 0;
        dp[1] = nums[1];
        for(int i = 2; i < n; i ++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        result = max(result, dp[n - 1]);
        return result;

        //没看清题目，我说怎么都是把环拆开分两组情况，艹了，没想到第一家和最后一家是连着的，果然编程不需要眼睛
        /*int n=nums.size();
        vector<int> dp(n,0);
        //cout<<n<<endl;
        int MaxNum=0;
        if(n==0) { return 0;}
        if(n==1) {return nums[0];}
        if(n==2) {return max(nums[0],nums[1]);}
        //cout<<"end"<<endl;
        dp[0]=nums[0];
        dp[1]=nums[1];
        //cout<<"2"<<endl;
        for(int i=2;i<n;i++)
        {
            dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
            MaxNum=max(dp[i],MaxNum);
            //cout<<MaxNum<<endl;
        }
        return MaxNum;*/
    }
};
// @lc code=end

