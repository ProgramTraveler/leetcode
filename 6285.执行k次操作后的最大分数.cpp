class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
      long long res = 0;
      
      sort (nums.begin(), nums.end());
      
      priority_queue<long long> heap;
      
      int n = nums.size() - 1;
      
      while (k --) {
        
        //cout << n << " ";
        
        if ((!heap.empty() && n >= 0 && heap.top() > nums[n]) || n < 0) {
            res += heap.top();
          
            long long tem = heap.top();
            heap.pop();
          
            heap.push(tem % 3 == 0 ? tem / 3 : tem / 3 + 1);
        
        } else if ((!heap.empty() && n >= 0 && nums[n] >= heap.top()) || heap.empty()) {
            res += nums[n];
          
            heap.push(nums[n] % 3 == 0 ? nums[n] / 3 : nums[n] / 3 + 1);
          
            n --;
        }
      }
      
      return res;
    }
}; 