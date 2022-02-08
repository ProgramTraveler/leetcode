/*
 * @lc app=leetcode.cn id=1748 lang=cpp
 *
 * [1748] 唯一元素的和
 */

// @lc code=start
class Solution {
    public int sumOfUnique(int[] nums) {
        int res = 0;
        Map<Integer, Integer> state = new  HashMap<Integer, Integer>();
        for (int num : nums) {
            if (!state.containsKey(num)) {
                res += num;
                state.put(num, 1);
            }else if (state.get(num) == 1) {
                res -= num;
                state.put(num, 2);
            }
        }
        return res;
    }
}
// @lc code=end

