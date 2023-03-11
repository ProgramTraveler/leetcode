/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < nums.size(); i ++) 
            map[nums[i]].push_back(i);
        //对map进行遍历操作，这个掌握一下，有的时候想写但写不出来
        for (auto &[u, cur] : map) {
            if (cur.size() > 1) {
                sort(cur.begin(), cur.end());
                int index = INT_MAX;
                for (int i = 1; i < cur.size(); i ++) {
                    index = min (index, cur[i] - cur[i - 1]);
                }
                if (index <= k) return true;
            }
        }
        return false;
    }
};

//这个是java版本的，利用了Set的特性
class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        int index = nums.length; //整个数组长度
        Set<Integer> set = new HashSet<>();

        for (int i = 0; i < index; i ++) {
            if (i > k) set.remove(nums[i - k - 1]);
            
            if (set.contains(nums[i])) return true;

            set.add(nums[i]);
        }
        return false;
    }
}
// @lc code=end

