/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<int> tem_ans;
        vector<vector<int>> answer;
        sort(nums.begin(), nums.end());
        // 找出a + b + c = 0
        // a = nums[i], b = nums[start], c = nums[last]
        int last;
        int start;
        for (int i = 0; i < nums.size(); i++) {
            // 排序之后如果第一个元素已经大于零，那么无论如何组合都不可能凑成三元组，直接返回结果就可以了
            if (nums[i] > 0)    return answer;
            // 正确去重方法
            if (i > 0 && nums[i] == nums[i - 1])    continue;
            start = i + 1;
            last = nums.size() - 1;
            while (last > start) 
            {
    
                if (nums[i] + nums[start] + nums[last] > 0)     last--;
                 
                else if (nums[i] + nums[start] + nums[last] < 0)     start++;
                
                else 
                {
                    tem_ans.push_back(nums[i]);
                    tem_ans.push_back(nums[start]);
                    tem_ans.push_back(nums[last]);

                    answer.push_back(tem_ans);
                    tem_ans.clear();
                    // 去重逻辑应该放在找到一个三元组之后
                    while (last > start && nums[last] == nums[last - 1]) last--;
                    while (last > start && nums[start] == nums[start + 1]) start++;
                    // 找到答案时，双指针同时收缩
                    last--;
                    start++;
                }
            }
        }
        return answer;
    }
};


// @lc code=end

