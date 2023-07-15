/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for (int a = 0; a < n - 3; a++) { // 枚举第一个数
            long long x = nums[a]; // 使用 long long 避免溢出
            if (a > 0 && x == nums[a - 1]) continue; // 跳过重复数字
            if (x + nums[a + 1] + nums[a + 2] + nums[a + 3] > target) break; // 优化一
            if (x + nums[n - 3] + nums[n - 2] + nums[n - 1] < target) continue; // 优化二
            for (int b = a + 1; b < n - 2; b++) { // 枚举第二个数
                long long y = nums[b];
                if (b > a + 1 && y == nums[b - 1]) continue; // 跳过重复数字
                if (x + y + nums[b + 1] + nums[b + 2] > target) break; // 优化一
                if (x + y + nums[n - 2] + nums[n - 1] < target) continue; // 优化二
                int c = b + 1, d = n - 1;
                while (c < d) { // 双指针枚举第三个数和第四个数
                    long long s = x + y + nums[c] + nums[d]; // 四数之和
                    if (s > target) d--;
                    else if (s < target) c++;
                    else { // s == target
                        ans.push_back({(int) x, (int) y, nums[c], nums[d]});
                        for (c++; c < d && nums[c] == nums[c - 1]; c++); // 跳过重复数字
                        for (d--; d > c && nums[d] == nums[d + 1]; d--); // 跳过重复数字
                    }
                }
            }
        }
        return ans;
    }
};
/*class Solution {
public:
    void Sum(vector<int>& nums,int target,int count,int sum){
        //递归结束的条件，当临时数组里面的数的个数达到4，而且和target的值一样，就存入ans
        if(temp.size()==4 && target==sum){
            ans.push_back(temp);
            return;
        }
        //递归
        for(int i=count;i<nums.size();i++){
            //去重
            if(i>count && nums[i]==nums[i-1]) continue;
            //剪枝 如果当前数字 + 已确定数字的和 + (n - 1) * 排序后数组中当前数字的下一个数字 > target，则说明后面的数无论怎么选，加起来都一定大于 target，所以剪掉（递归返回）；
            else if (i<nums.size()-1 && sum+nums[i]+int(3-temp.size())*nums[i + 1]>target)
                return;
            //剪枝 如果当前数字 + 已确定数字的和 + (n - 1) * 排序后数组最后一个数字 < target，则说明后面的数无论怎么选，加起来都一定小于 target，所以剪掉（进行下一次循环）；
            else if (i<nums.size()-1 && sum+nums[i]+int(3-temp.size())*nums[nums.size()-1]<target)
                continue;
            else{
                temp.push_back(nums[i]);
                Sum(nums,target,i+1,sum+nums[i]);
                temp.pop_back();
            }
        }
        return;

    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<4) return ans; //如果数量不足4个，直接返回
        sort(nums.begin(),nums.end()); //对数组进行排序，方便剪枝（不剪枝的话会超时）
        Sum(nums,target,0,sum);
        return ans;

    }
private:
    vector<int> temp; //记录每条分支的结果
    vector<vector<int>> ans; //保存最后答案
    int sum=0; //每次计算的值
};*/
// @lc code=end

