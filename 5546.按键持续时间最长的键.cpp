/*
 * @lc app=leetcode.cn id=5546 lang=cpp
 *
 * [5546] 按键持续时间最长的键
 */

// @lc code=start
class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int t = releaseTimes[0];
        char ans=keysPressed[0];
        for(int i=1;i<releaseTimes.size();i++){
            if(releaseTimes[i]-releaseTimes[i-1]>=t) {//顺序更新无需比较相同次数的不同字符
                ans = keysPressed[i];
                t = releaseTimes[i]-releaseTimes[i-1];
            }
        }
        return ans;
    }
};

// @lc code=end

