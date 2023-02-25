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

* 二分查找
* 在这个题中关键还是对公式的变形 其中用到的 **lower_bound** 和 **upper_bound**
* lower_bound 用于查找容器中 **大于等于** 某值的数 返回这个数的指针
* upper_bound 用于查找容器中 **大于** 某值的数 返回这个数的指针
* 注意二分的边界

```cpp
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());

        long long res = 0; // 数据挺大的
    
        for (int i = 0; i < nums.size(); i ++) {
            int l = lower - nums[i];
            int r = upper - nums[i];
    
            int cou_1 = lower_bound(nums.begin(), nums.end(), l) - nums.begin(); // 下标
    
            int cou_2 = upper_bound(nums.begin(), nums.end(), r) - nums.begin(); // 下标

            // j 的范围是 [cou_1, cou_2) 且 i < j
            if (cou_1 <= i && cou_2 > i) res += cou_2 - i - 1;
    
            else if (i < cou_1) res += cou_2 - cou_1;
        }
    
        return res;
    }
};

```

---

### 2023-02-18 第 98 场双周赛

[替换一个数字后的最大差值](https://leetcode.cn/problems/maximum-difference-by-remapping-a-digit/)

* 这个最初看题的时候有点懵 但是很快就想到了一个大概的思路
* 最小的数肯定就是将第一位的数字变成 0 最大的就是将最靠前的数字变成 9 因为第一位数字可能已经是 9 了 所以尽可能选择靠前的数字 这样才是最大的

```cpp
class Solution {
public:
    int minMaxDifference(int num) {
        stack<int>res_max;
        
        stack<int>res_min;
        
        int tem = num;
        
        int sta_max = 9, sta_min = 0, sta = 0;
        
        while (tem) {
            sta = tem % 10;
                
            sta_min = sta;
            
            if (sta != 9) sta_max = sta;
            
            tem = tem / 10;
        }
        
        tem = num;
        
        while (tem) {
            int tem_n = tem % 10;
            
            if (tem_n == sta_max) res_max.push(9);
            
            
            else res_max.push(tem_n);
            
            if (tem_n == sta_min) res_min.push(0);
            
            else res_min.push(tem_n);
            
            tem = tem / 10;
        }
        
        long long res_x = 0, res_i = 0;
        
        while (!res_max.empty()) {
            res_x = res_x * 10 + res_max.top();
            
            res_max.pop();
        }
        
        while (!res_min.empty()) {
            res_i = res_i * 10 + res_min.top();
            
            res_min.pop();
        }
            
        return res_x - res_i;

    }
};
```

[修改两个元素的最小分数](https://leetcode.cn/problems/minimum-score-by-changing-two-elements/)

* 卡住了 实在是没有思路

```cpp
class Solution {
public:
    int minimizeSum(vector<int>& nums) { 
        // 两个数的最小值肯定是满足最小值是 0 的情况 在这个条件下的最大值也要尽可能的小
        
        if (nums.size() == 3) return 0;
        
        int count = 0; // 最大值出现的次数
        
        int ans_ma = INT_MIN, ans_mi = 0;
        
        for (int i = 1; i < nums.size(); i ++) {
            int tem = abs(nums[i] - nums[i - 1]);
            
            ans_ma = max(ans_ma, tem);
        }
        
        int sta = 0, end = 0;
        
        for (int i = 1; i < nums.size(); i ++) {
            
            int tem = abs(nums[i] - nums[i - 1]);
            
            if (ans_ma == tem) count ++, sta = i - 1, end = i;
        }
        
        if (count > 1) return ans_ma;
        
        int sta_fro = INT_MAX, end_beh = INT_MAX;
        
        if (sta > 0) sta_fro = nums[sta - 1];
        
        if (end < nums.size() - 1) end_beh = nums[end + 1];
        
        int num_min = min(sta_fro, end_beh);
        
        nums[sta] = num_min, nums[end] = num_min;
        
        ans_ma = 0;
        
        for (int i = 1; i < nums.size(); i ++) {
            int tem = abs(nums[i] - nums[i - 1]);
            
            ans_ma = max(ans_ma, tem);
        }
        
        return ans_ma;
        
        
    }
};
```

* 大为震惊 脑经急转弯

* 具体思路可以看[传送门](https://www.bilibili.com/video/BV15D4y1G7ms/?spm_id_from=333.337.search-card.all.click&vd_source=c68460d92fb2b166884357ad8c98de03)

```cpp
class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        return min({nums[n - 3] - nums[0], nums[n - 2] - nums[1], nums[n - 1] - nums[2]});
    }
};
```

---

### 2023-02-19 第 333 场周赛

[合并两个二维数组](https://leetcode.cn/problems/merge-two-2d-arrays-by-summing-values/)

* 第一题直接 A

```cpp
class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> res;
        
        unordered_map<int, int> al;
        
        for (int i = 0; i < nums1.size();i ++) al[nums1[i][0]] += nums1[i][1];
        
        for (int i = 0; i < nums2.size(); i ++) al[nums2[i][0]] += nums2[i][1];
        
        for (auto [k, v] : al) {
            //cout << k << " " << v << endl;
            res.push_back({k, v});
        }
            
        sort(res.begin(), res.end());
        
        return res;
    }
};
```

[将整数减少到零需要的最少操作数](https://leetcode.cn/problems/minimum-operations-to-reduce-an-integer-to-0/)

* 贪心 难得将第二题 A 出来

```cpp
class Solution {
public:
    bool fun(int n) { // 检查是不是 2 的某个次幂
        while (n) {
            if (n != 1 && n % 2 != 0) return false; // 有奇数 说明不是 2 的某个次幂
            
            n /= 2;
        }
        
        return true;
    }
    
    /*int cout(int n) { // 变成 2 的 某个次幂需要的步数 前提是偶数
        int ans = 0;
        while ()
    }*/
    
    void count(vector<int>& res, int n) {
        int l = 1, r = 1;
        
        if (fun(n)) {
            //cout << n << ' ' << " end " << endl;
            res.push_back(n);
            
            return ;
        }
        
        while (r < n) r *= 2;
        
        l = r / 2;
        
        //cout << l << ' ' << r << endl;
        
        if ((n - l) > (r - n)) res.push_back(r), count(res, r - n);
        
        else res.push_back(l), count(res, n - l);
    }
    
    int minOperations(int n) { // 应该是贪心 构造 2 的某个幂的最少次数
        
        vector<int> res;
        
        count(res, n);
        
        //for (int i = 0; i < res.size(); i ++) cout << res[i] << ' ';
        
        //cout << endl;
        
        
        return res.size();
        
    }
};
```

[无平方子集计数](https://leetcode.cn/problems/count-the-number-of-square-free-subsets/description/)

* 本来以为能 A 的 没想到还是出错了

```cpp
class Solution {
public:
    bool fun(int n) {
        
        cout << "in: " << n << endl;
        
        //if (n < 4) return true;
        
        int idx = 2, mi = 2;
        
        while (mi < n) {
            
            mi = idx * idx;
            
            if (n % mi == 0) return false;
            
            idx ++;
        }
        
        return true;
    }
    
    int squareFreeSubsets(vector<int>& nums) { // 首先应该是找出 无平方因子数
        /*unordered_map<int, bool> al;
    
        
        for (int i = 0; i < nums.size(); i ++) {
            al[nums[i]] = fun(nums[i]);
        }*/
        
        
        /*int l = 0, r = 0;
        
        
        
        int ans = 0;
        
        for (int i = 0; i < res.size(); i ++) cout << res[i] << " ";
        
        cout << endl;
        
        for (int i = 0; i < nums.size(); i ++) {
            int tem = nums[i];
            int cou = 1;
            
            while (tem) {
                cou *= tem;
                
                tem -= 1;
            }
            
            ans += cou;
        }
        
        return ans;*/
        
        vector<int> res;
        
        for (int i = 0; i < nums.size(); i ++) if (fun(nums[i])) res.push_back(nums[i]);
        
        for (int i = 0; i < res.size(); i ++) cout << res[i] << ' ';
        
        cout << endl;
        
        // 排列组合 ？ 按正常的数学方式求
        
        int n = res.size();
        
        int ans = 0;
        
        ans += n; // 1 个 和 全组合的情况
        
        if (n > 1) ans += 1;
        
        int idx_1 = 1;
        
        int tem = n;
        
        while (tem) idx_1 *= tem, tem -= 1;
        
        for (int i = 2; i < n; i ++) {
            int temp = i, idx_2 = 1;
            
            while (temp) idx_2 *= temp, temp -= 1;
            
            ans += idx_1 / idx_2;
        }
        
        return ans;
        
    }
};
```
