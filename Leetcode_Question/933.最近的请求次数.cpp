/*
 * @lc app=leetcode.cn id=933 lang=cpp
 *
 * [933] 最近的请求次数
 */

// @lc code=start
class RecentCounter {
public:
    RecentCounter() {

    }
    
    int ping(int t) {
        que.push(t);
        while (que.front() < t - 3000)
            que.pop();
        return que.size();

    }
private:
    queue<int> que;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// @lc code=end

