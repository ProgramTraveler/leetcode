/*
 * @lc app=leetcode.cn id=1093 lang=cpp
 *
 * [1093] 大样本统计
 */

// @lc code=start
class Solution {
public:
    float func(int f, vector<int>& count, vector<int>& nums) {
        int id = 0;
        
        int k = 0;

        while(f > id && k < nums.size()) {
            id += count[nums[k]];

            k ++;
        }

        k --;

        return static_cast<float>(nums[k]);
    }
    vector<double> sampleStats(vector<int>& count) {
        // count 是这个数出现的次数
        double minmum = 0, maxmum = 0, mode = 0;

        float mean = 0, median = 0;

        vector<int> nums;

        for (int i = 0; i < count.size(); i ++) if (count[i] != 0) nums.emplace_back(i);

        vector<double> res;
        
        int n = nums.size();
        // 最大数和最小数
        minmum = nums[0], maxmum = nums[n - 1];

        int cnt = 0;
        for (int i = 0; i < n; i ++) cnt += count[nums[i]];

        // 平均数
        for (int i = 0; i < n; i ++) {
            mean += 1.0 * nums[i] * count[nums[i]] / cnt;
        }

        // 中位数
        if (cnt % 2 != 0) {
            
            median = func(cnt / 2 + 1, count, nums);

        } else {
            median = func(cnt / 2, count, nums);

            median += func(cnt / 2 + 1, count, nums);

            median = 1.0 * median / 2;

        }


        int idx = 0;

        for (int i = 0; i < n; i ++) if (count[nums[i]] > idx) idx = count[nums[i]], mode = nums[i];
        
        res.emplace_back(minmum);
        res.emplace_back(maxmum);
        res.emplace_back(static_cast<double>(mean));
        res.emplace_back(static_cast<double>(median));
        res.emplace_back(mode);
       
        return res;

        /* 审错题
        // 关键是保证精度
        sort(count.begin(), count.end());

        vector<double> res;

        // 最小数
        res.emplace_back(count[0]);
        // 最大数
        res.emplace_back(count[1]);

        long long sum = 0;

        unordered_map<double, int> cnt;

        for (int i = 0; i < count.size(); i ++) sum += count[i], cnt[count[i]] ++;

        int n = count.size();

        // 平均数
        res.emplace_back(1.0 * sum / n);

        // 中位数
        if (n % 2 == 0) res.emplace_back(1.0 * (count[n / 2] + count[n / 2 - 1]) / 2);

        else res.emplace_back(count[n / 2]);

        double tem = 0, tem_num = 0;

        for (auto &[k, v] : cnt) if (v > tem_num) tem = k;
        // 众数        
        res.emplace_back(tem);

        return res;
        */
    }

};
// @lc code=end

