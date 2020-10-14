/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
//使用map映射的方式（<数字，出现的次数>）

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
     {
        map<int,int> m;
        vector<int> ans;
        //先迭代最长的数组
        if(nums1.size()>nums2.size()) return intersect(nums2,nums1);
        else
            {
                for(auto i:nums1) //迭代nums1中的数字
                {
                    m[i]++;
                }
                for(auto i:nums2)
                {
                    if(m[i]>0) 
                    {
                        ans.push_back(i); //把相同的压入数组ans中
                        m[i]--; //次数减一
                    }
                }
            } 
        return ans;
    }
};
// @lc code=end

