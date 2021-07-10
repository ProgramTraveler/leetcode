/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //定义一个map来记录数字的个数
        unordered_map<int,int> ans;
        //开始比较
        for(auto x:nums)
            if (ans[x] ++ ) return true;
        return false;
    }
    /*
    这是用双指针的思想写的，但在第17个测试用例的时候超时了，我看题解大部分是hash或者就直接排序，就想试试这个方法。
    
    bool containsDuplicate(vector<int>& nums) {
        //如果nums中的数字个数小于2，直接返回false
        if(nums.size() <= 1) return false; 
        //头指针为0，表示从第一个数字开始
        int First = 0;
        //开始比较
        while(First < nums.size()-1){
            //尾指针从头指针的后面开始
            int Second = First + 1;
            //依次比较后面的数字
            while(Second < nums.size()){
                //如果发现相同的数字直接就返回true
                if(nums[First] == nums[Second]) return true;
                //否则就向后比较
                else Second++; 
            }
            //数字后移
            First++;
        }
        //比较完后都没有的话就返回false
        return false;
    }*/
};
// @lc code=end

