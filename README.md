## LeetCode的日常刷题记录

### 2023-02-12 第 332 场周赛

[找出数组的串联值](https://leetcode.cn/problems/find-the-array-concatenation-value/)

* 第一题没什么可说的 直接模拟就能 AC

```cpp
class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long res = 0;
        
        int l = 0, r = nums.size() - 1;
        
        while (l < r) {
            long long l_tem = nums[l], r_tem = nums[r];
            
            while (r_tem > 0) {
                l_tem = l_tem * 10;
                
                r_tem /= 10;
            }
            
            l_tem += nums[r];
            
            res += l_tem;
            
            l++, r--;
        }
        
        return l == r ? res += nums[l] : res;
    }
};
```

[统计公平数对的数目](https://leetcode.cn/problems/count-the-number-of-fair-pairs/description/)

* 最开始看见这个题的的数据大小我就知道暴力应该是会超时的 所以在循环中加入了一些判断条件 但无奈还是没有 AC 最后还是超时了

* 当时也想到了用排序后的结果来试试 但无奈没有具体思路

```
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        // 不能排序 时间复杂度 
        
        int res = 0;
        
        int n_max = INT_MIN, n_min = INT_MAX;
        
        for (int i = 0; i < nums.size(); i ++) n_max = max(n_max, nums[i]), n_min = min(n_min, nums[i]);
        
        for (int i = 0; i < (nums.size() - 1); i ++) {
            if (nums[i] + n_max < lower || nums[i] + n_min > upper) continue;
            
            else {
                
                 for (int j = i + 1; j < nums.size(); j ++) {
                    
                    long long tem = nums[i] + nums[j];
                
                    if (tem >= lower && tem <= upper) res ++;
         
                }   
            }
        
        }
    
        return res;
    }
};
```

* 
---