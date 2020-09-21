/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        vector<int> result;
        if(nums.size()==0)
        {
            return result;
        }

        deque<int> que; //que记录的都是nums[]里的下标，不是nums里的数，感觉用数也可以（我没试过）
        for(int i=0;i<nums.size();i++)
        {
            while(!que.empty() && nums[i]>=nums[que.back()])
            {
                que.pop_back(); //删除末尾的元素（a.push_back（num）在末尾添加元素）
            }
            que.push_back(i); // 把元素放在队列后面（如果前面有元素），没有的话放在后面也就是在第一个

            if(que.front()==i-k)
            {
                que.pop_front(); // 如果元素超过了窗口的大小，把第一个元素删掉
            }
            if(i>=k-1) // 保持每次窗口都在规定大小
            {
                result.push_back(nums[que.front()]); //如果满足大小就把第一个最大的数放进数组
            }
        }
        return result;
    }
};
// @lc code=end

