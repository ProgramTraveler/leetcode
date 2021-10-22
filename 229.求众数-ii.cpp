/*
 * @lc app=leetcode.cn id=229 lang=cpp
 *
 * [229] 求众数 II
 */

// @lc code=start
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //题解用的是摩尔投票，暂时还没了解，只想到map
        vector<int> res;
        unordered_map<int, int> m;
        int n = nums.size();
        for (int i= 0; i < nums.size(); i ++) { //对数组中出现的数字计数
            //本来是想用一个循环解决的，但是逻辑好像有问题，没找到原因
            /*if (m[nums[i]] ++ > n / 3  && m[nums[i]] ++ <= n / 3 ) {
                cout<< m[nums[i]]<<endl;
                res.push_back(nums[i]);
            }else {
                m[nums[i]] ++;
                cout<< n / 3<<" "<<n / 3 + 1<<" "<< m[nums[i]]<<endl;
            }*/
            m[nums[i]] ++;
        }
        for (auto & c : m) {
                if (c.second > n / 3)
                    res.push_back(c.first);
            }

        return res;
    }
};
// @lc code=end

