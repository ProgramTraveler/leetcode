class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        // 两层循环应该可以做
        // nums 中的整数互不相同 说明中位数 k 只有一个
        // 中位数是按递增顺序排列后位于中间位置的元素
        // 难点就在于排序 不能每次都排一下序吧
        int pos = find(nums.begin(), nums.end(), k) - nums.begin(); // 查找出 k 的位置

        unordered_map<int, int> cnt{{0, 1}};

        for (int i = pos - 1, x = 0; i >= 0; i --) {
            x += nums[i] > k ? -1 : 1;

            cnt[x] ++;
        }

        int res = cnt[0] + cnt[-1]; // 奇数和偶数的次数

        for (int i = pos + 1, x = 0; i < nums.size(); i ++) {
            x += nums[i] > k ? 1 : -1;

            res += cnt[x] + cnt[x - 1];
        }

        return res;



        /* 思路有错误
        
        int res = 0;
        vector<vector<int>> al;

        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] == k) {
                int tem = min(nums.size() - 1 - i, i - 0);

                al.push_back({i - tem, i + tem});
            }
        }



        return res;*/
    }
};