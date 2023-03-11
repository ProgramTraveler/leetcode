/*
 * @lc app=leetcode.cn id=1144 lang=cpp
 *
 * [1144] 递减元素使数组呈锯齿状
 */

// @lc code=start
class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) { // 正常做？ 注意下标越界的问题
        int res = INT_MAX, cnt = 0;

        vector<int> tem;

        tem.assign(nums.begin(), nums.end()); // 复制 nums

        for (int i = 0; i < nums.size(); i += 2) { // 先考虑从 0 开始的数组
            //cout << "in" << endl;
            if (i == 0 && (i + 1) < nums.size()) {

                if (nums[i + 1] >= nums[i]) cnt += nums[i + 1] - nums[i] + 1, nums[i + 1] = nums[i] - 1;
                
            } else if (i == nums.size() - 1 && (i - 1) >= 0) {

                if (nums[i - 1] >= nums[i]) cnt += nums[i - 1] - nums[i] + 1, nums[i] = nums[i - 1] - 1;
                
            } else if ((i + 1) < nums.size() && (i - 1) >= 0){

                if (nums[i - 1] >= nums[i]) cnt += nums[i - 1] - nums[i] + 1, nums[i - 1] = nums[i] - 1;

                if (nums[i + 1] >= nums[i]) cnt += nums[i + 1] - nums[i] + 1, nums[i + 1] = nums[i] - 1;
            }
        }

        res = min(cnt, res);

        cnt = 0;

        for (int i = 1; i < tem.size(); i += 2) { // 从 1 开始的数组
            //cout << "a" << endl;
            if (i == tem.size() - 1 && (i - 1) >= 0) {

                if (tem[i - 1] >= tem[i]) cnt += tem[i - 1] - tem[i] + 1, tem[i - 1] = tem[i] - 1;

            } else if ((i - 1) >= 0 && (i + 1) < nums.size()) {

                if (tem[i - 1] >= tem[i]) cnt += tem[i - 1] - tem[i] + 1, tem[i - 1] = tem[i] - 1;

                if (tem[i + 1] >= tem[i]) cnt += tem[i + 1] - tem[i] + 1, tem[i + 1] = tem[i] - 1;
            }
        }

        res = min(cnt, res);

        return res;

    }
}; 
// @lc code=end

