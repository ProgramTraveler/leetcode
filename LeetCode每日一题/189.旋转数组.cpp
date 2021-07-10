/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */

// @lc code=start
class Solution {
public:
/*
时间复杂度是O(n)，但用到了新的数组空间，所以内存的使用大一点
*/
    void rotate(vector<int>& nums, int k) {
        //获取数组的长度
        int n = nums.size();
        //定义一个新的数组
        vector<int> newArr(n);
        //将原数组中移动后的数存进新的数组中
        for (int i = 0; i < n; ++i) 
            newArr[(i + k) % n] = nums[i];
        //将新数组的值拷贝到新数组中
        nums.assign(newArr.begin(), newArr.end());
    }
};

// @lc code=end

