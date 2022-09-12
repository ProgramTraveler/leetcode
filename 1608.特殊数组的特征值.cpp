/*
 * @lc app=leetcode.cn id=1608 lang=cpp
 *
 * [1608] 特殊数组的特征值
 */

// @lc code=start
/*
class Solution {
public:
    int specialArray(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i <= 1000; i ++){
            for(int j = 0; j < nums.size(); j ++){
                if(nums[j] >= i) {
                    count ++;
                }
            }
            if(count == i) return i;
            else count = 0;        
        }
        return -1;
    }
};*/

class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>()); //对数组进行排序

        int n = nums.size();

        for (int i = 1; i <= n; ++ i) {
            if (nums[i - 1] >= i && (i == n || nums[i] < i)) return i;
        }

        return -1;
    }
};
// @lc code=end

