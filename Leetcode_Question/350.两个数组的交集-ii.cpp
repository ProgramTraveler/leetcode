/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
//使用map映射的方式（<数字，出现的次数>）

/*
    这段代码出现的应该是数组越界了，但暂时还没有好的解决办法，同时对于引用的使用有待测试
*/
/*class Solution {
public:
    void quick_sort(vector<int>& nums, int l , int r) {
        if (l >= r) return ;
        int x = nums[l + r >> 1];
        int i = l - 1;
        int j = r + 1;
        while (l < r) {
            do i ++; while (x > nums[i]);
            do j --; while (x < nums[j]);
            if (i < j) swap(nums[i], nums[j]);
        }
        quick_sort(nums, l, j);
        quick_sort(nums, j + 1, r);
    }
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        //quick_sort(nums1, 0, nums1.size() - 1);
        //quick_sort(nums2, 0, nums2.size() - 1);
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        //cout<<"a"<<endl;
        vector<int> res;
        int flag1 = 0, flag2 = 0;
        while (flag1 < nums1.size() && flag2 < nums2.size()) {
            if (nums1[flag1] > nums2[flag2]) flag2 ++;
            if (nums1[flag1] < nums2[flag2]) flag1 ++;
            if (nums1[flag1] == nums2[flag2]) {
                res.push_back(nums1[flag1]);
                flag1 ++;
                flag2 ++;
            }
        }
        return res;
    }
};*/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> m;
        vector<int> ans;
        if(nums1.size() > nums2.size()) return intersect(nums2, nums1);
        else {
                for(auto i : nums1) {
                    m[i] ++;
                }
                for(auto i : nums2) {
                    if(m[i] > 0) {
                        ans.push_back(i);
                        m[i] --;
                    }
                }
            } 
        return ans;
    }
};
// @lc code=end

