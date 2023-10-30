class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // 直接最大堆
        priority_queue<int> heap(nums.begin(), nums.end());

        int res = 0;

        while (k --) {
            res = heap.top();

            heap.pop();
        }

        return res;
    }
};