/*
 * @lc app=leetcode.cn id=703 lang=cpp
 *
 * [703] 数据流中的第 K 大元素
 */

// @lc code=start
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        target = k;
        for (auto x : nums) {
            heap.push(x);
            if (heap.size() > target)
                heap.pop();
        }
    }
    int add(int val) {       
        heap.push(val);
        if (heap.size() > target)
            heap.pop();
        return heap.top();
    }
private :
    //小根堆，依次分别是<类型,<存储方式>,<比较函数>>
    priority_queue<int, vector<int>, greater<int>> heap;
    int target;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end

