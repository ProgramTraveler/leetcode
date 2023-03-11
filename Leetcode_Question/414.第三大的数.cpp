/*
 * @lc app=leetcode.cn id=414 lang=cpp
 *
 * [414] 第三大的数
 */

// @lc code=start
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        /* set<int> s(nums.begin(), nums.end());
        auto it = s.end();
        it --;
        if(s.size() >= 3) { 
            it --;
            it --;
        }
        return *it; */
        set<int> res;
        for (int num : nums) {
            res.insert(num);
            if (res.size() > 3) {
                res.erase(res.begin()); //当res里的数字大于三时，删掉第一个元素，因为此时第一个是最小的
            }
        }
        return res.size() == 3 ? *res.begin() : *res.rbegin(); //rbegin() 反向迭代器
    }
};

// @lc code=end

