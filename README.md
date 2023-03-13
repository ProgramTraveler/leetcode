## LeetCode的周赛记录

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

---

### 2023-02-26 第 334 场周赛

[左右元素和的差值](https://leetcode.cn/problems/left-and-right-sum-differences/description/)

* 第一题依旧是水题 直接按题目意思就能 A

```cpp
class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        vector<int> res;
        
        for (int i = 0; i < nums.size(); i ++) {
            int l = 0, r = 0;
            
            int k = i - 1, j = i + 1;
            
            while (k >= 0) l += nums[k], k --;
            
            while (j < nums.size()) r += nums[j], j ++;
            //for (int k = i - 1; i >= 0; i --) l += nums[k];
            
            //for (int j = i + 1; i < nums.size(); i ++) r += nums[j];
            
            res.push_back(abs(l - r));
        }
        
        return res;
    }
};
```

[找出字符串的可整除数组](https://leetcode.cn/problems/find-the-divisibility-array-of-a-string/description/)

* 这个题主要是处理数据溢出的问题 花费的时间比较多 而且罚了 4 次时
* 最开始是直接模拟的 然后 int 溢出 改成 long long 后数据还是溢出 最后对数据的处理进行优化 但时间超时 最后才想到这个思路
* 其实思路也不难想 就是对数据的溢出缺点想法

```cpp
class Solution {
public:
    vector<int> divisibilityArray(string word, int m) { // 数据溢出 所以想模拟除法
        /*vector<int> res;
        
        vector<int> tem;
        
        long long f = 0, idx = 0; // 记录下标 被除数
        
        // 处理下标位置
        int w = m;
        
        while (w / 10) {
            w = w % 10;
            
            
            //w = w / 10;
            
            f ++;
        }
        
        f = f + 2 - 1 - 1;
        
        cout << "f: " << f << endl;
        
        for (int i = 0; i < f; i ++) tem.push_back(word[i] - '0'), res.push_back(0);
        
        for (int i = f; i < word.size(); i ++) {
            
            tem.push_back(word[i] - '0');
            
            idx = 0;
            
            // 模拟除法
            while (f < tem.size()) {
                idx = idx * 10 + tem[f]; // 被除数
                
                idx = idx % m;
                
                f ++;
                
            }
            
            if (idx == 0) res.push_back(1);
            
            else res.push_back(0);
        }*/
        vector<int> res;
        
        vector<int> tem;
        
        long long f = 0, idx = 0; // 记录下标 被除数
        
        for (int i = 0; i < word.size(); i ++) {
            idx = idx * 10 + (word[i] - '0');
                
            idx = idx % m;
            
            if (idx == 0) res.push_back(1);
            
            else res.push_back(0);
        }
        
        return res;
    }
};
```

[求出最多标记下标](https://leetcode.cn/problems/find-the-maximum-number-of-marked-indices/)

* 初次 A 到第三题 感觉应该可以上 1500
* luck day
* 正常处理就行 排序加贪心

```cpp
class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<int> sma, big;
        
        int idx = nums.size() / 2;
        
        for (int i = 0; i < idx; i ++) sma.push_back(nums[i] * 2);
        
        for (int i = idx; i < nums.size(); i ++) big.push_back(nums[i]);
        
        int l = 0, r = 0;
        
        int res = 0;
        
        while (l < sma.size() && r < big.size()) {
            
            if (sma[l] <= big[r]) l ++, r ++, res ++;
            
            else r ++;
        }
        
        return res * 2;
    }
};
```

---

### 2023-03-05 第 335 场周赛

* 这次周赛其实挺简单的 我感觉能做但是实际效果却不是很理想

[递枕头](https://leetcode.cn/problems/pass-the-pillow/)

* 第一题没有一次 A 掉
* 失误了 本来想整波花活 结果整出事了
* 罚时一次

```cpp
class Solution {
public:
    int passThePillow(int n, int time) {
        /*int idx_1 = time / n;
        
        int idx_2 = time % n;
        
        int res = 0;
        
        if (idx_1 % 2 == 0) {
            res = 1 + idx_2;
        } else {
            res = n - idx_2 - 1;
        }
        
        return res;*/
        
        int res = 1, f = false;
        
        while (time) {
            if (res == n) f = true;
            
            if (res == 1) f = false;
            
            if (f) res --, time --;
            
            else res ++, time --;
         }
        
        return res;
    }
};
```

[二叉树中的第K大层数和](https://leetcode.cn/problems/kth-largest-sum-in-a-binary-tree/)

* 第二题花费了太多的时间
* 题型是见过的
* 陷入了怎么判断树的节点具体是哪一层的瓶颈
* 最后也没有 A 掉...

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long> st(1e5 + 10, 0);
        
        int res = 0, idx = 0;
    
        queue<TreeNode*> qu;
        
        qu.push(root);
        
        idx = 0;
        
        st[idx] = (qu.front() -> val), idx ++;
        
        while (!qu.empty()) {
            
            if (qu.front() -> left != nullptr) qu.push(qu.front() -> left), st[idx] = (qu.front() -> left -> val), idx ++;
            
            else idx ++;
            
            
            if (qu.front() -> right != nullptr) qu.push(qu.front() -> right), st[idx] = (qu.front() -> right ->val), idx ++;
            else idx ++;
            
            
            qu.pop();
            
        }
        
        //for (int i = 0; i < 6; i ++) cout << st[i] << endl;
        
        vector<long> ans;
        
        ans.push_back(st[0]);
        
        int l = 0 * 2 + 1, r = 0 * 2 + 2;
        
        res = st[0];
        
        while (res != 0) {
            res = 0;
            
            int tem_l = l, tem_r = r;
            
            while (l <= r) {
                res += st[l];
                
                l ++;
            }
            
            ans.push_back(res);
            
            l = tem_l * 2 + 1;
            r = tem_r * 2 + 2;
        }
        
        
        sort(ans.begin(), ans.end());
        
        int c = ans.size() - 1;
        
        while (k --) {
            res = ans[c];
            
            c --;
        }
        
        return res;
    }
};

* 使用 BFS 来解决这样的问题
* 双数组
* 这样的题应该是第二次遇到了 下次不会再出错了

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<TreeNode*> q;

        vector<long long> sum;

        q.push_back(root);

        // q.clear();

        //cout << q.size() << endl;

        while (q.size() > 0) {
            vector<TreeNode*> tem;

            long long s = 0;

            tem = q, q.clear();

            for (auto node : tem) {
                s += node -> val;

                if (node -> left) q.push_back(node -> left);

                if (node -> right) q.push_back(node -> right);
            }

            sum.push_back(s);
        }

        sort(sum.begin(), sum.end());

        int n = sum.size();

        return n < k ? -1 : sum[n - k];
    }
};
```

```

[分割数组使乘积互质](https://leetcode.cn/problems/split-the-array-to-make-coprime-products/)

* 这题看第一眼感觉不难
* 但是第二题花的时间有点多 没时间做优化
* 最后是数字溢出了 应该还是大数的问题

```cpp
class Solution {
public:
    int findValidSplit(vector<int>& nums) {
        int n = nums.size() - 2;
        
        int l = 0, r = 0;
        
        int res = -1;
        
        long long s = 1;
        
        for (int i = 0; i < nums.size(); i ++) s *= nums[i];
        
        while (l <= n) {
            long long tem_1 = 1, tem_2 = 1;
            
            for (int i = 0; i <= l; i ++) tem_1 *= nums[i];
            
            tem_2 = s / tem_1;
            
            cout << tem_1 << ' ' << tem_2 << endl;
            
            if (gcd(tem_1, tem_2) == 1) {
                res = l; 
                break;
            }
            
            //cout << gcd(tem_1, tem_2) << endl;
            
            l ++;
        }
        
        return res;
    }
};
```

---