/*
 * @lc app=leetcode.cn id=765 lang=cpp
 *
 * [765] 情侣牵手
 */

// @lc code=start
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int ans = 0; //记录每次交换的结果
        unordered_map<int, int> memo; //记录情侣编号和下标
        //遍历座位，记录情侣编号所属的下标
        for (int i = 0; i < row.size(); i ++) 
            memo[row[i]] = i;
        int target = 0; //目标情侣的编号
        for (int i = 0; i < row.size(); i += 2) {
            //判断当前数是奇数还是偶数
            target = (row[i] & 1) ? row[i] - 1 : row[i] + 1;
            //如果要找的情侣就在你的身边
            if (row[i + 1] == target)
                continue; //直接去牵手下一对情侣
            //将该情侣的下一个人和目标调换位置，这样他们就可以牵手了
            swap(row[i + 1], row[memo[target]]);
            //调换后情侣编号和下标也要做调换
            swap(memo[target], memo[row[memo[target]]]);
            ans ++; //调换次数加一
            
        }
        //返回最后的结果
        return ans;
    }
};
// @lc code=end

