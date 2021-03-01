/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
class NumArray {
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        sum.resize(n + 1); 
        for (int i = 0; i < nums.size(); i ++) {
            sum[i + 1] = sum[i] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        return (sum[j + 1] - sum[i]);
    }
private:
    vector<int> sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
// @lc code=end

